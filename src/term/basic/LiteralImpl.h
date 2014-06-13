#ifndef LITERAL_H_
#define LITERAL_H_

/**
 * @file
 * Provide a basic implementation of literals.
 *
 * @author sprowell@gmail.com
 *
 * @section LICENSE
 * @verbatim
 *       _ _     _
 *   ___| (_)___(_) ___  _ __
 *  / _ \ | / __| |/ _ \| '_ \
 * |  __/ | \__ \ | (_) | | | |
 *  \___|_|_|___/_|\___/|_| |_|
 * The Elision Term Rewriter
 *
 * Copyright (c) 2014 by Stacy Prowell (sprowell@gmail.com)
 * All rights reserved.
 * @endverbatim
 */

#include "TermImpl.h"
#include "term/ILiteral.h"

namespace elision {
namespace term {
namespace basic {

using namespace elision;
using namespace elision::term;


class SymbolLiteralImpl : public ISymbolLiteral, public TermImpl {
public:
	inline virtual std::string const get_name() const {
		return name_;
	}
	inline virtual bool is_constant() const {
		return true;
	}
	virtual std::string to_string() const;

	inline bool is_equal(ITerm const& other) const {
		auto oth = dynamic_cast<SymbolLiteralImpl const&>(other);
		return get_name() == oth.get_name();
	}

	inline TermKind get_kind() const {
		return SYMBOL_LITERAL;
	}

private:
	friend class TermFactoryImpl;
	SymbolLiteralImpl(Locus the_loc, std::string the_name, pTerm the_type);
	std::string const name_;
};


class StringLiteralImpl : public IStringLiteral, public TermImpl {
public:
	inline virtual std::string const get_value() const {
		return value_;
	}
	inline virtual bool is_constant() const {
		return true;
	}
	virtual std::string to_string() const;

	inline bool is_equal(ITerm const& other) const {
		auto oth = dynamic_cast<StringLiteralImpl const&>(other);
		return get_value() == oth.get_value();
	}

	inline TermKind get_kind() const {
		return STRING_LITERAL;
	}

private:
	friend class TermFactoryImpl;
	StringLiteralImpl(Locus the_loc, std::string the_value, pTerm the_type);
	std::string const value_;
};


class IntegerLiteralImpl : public IIntegerLiteral, public TermImpl {
public:
	inline virtual eint_t get_value() const {
		return value_;
	}
	inline virtual bool is_constant() const {
		return true;
	}
	virtual std::string to_string() const;

	inline bool is_equal(ITerm const& other) const {
		auto oth = dynamic_cast<IntegerLiteralImpl const&>(other);
		return get_value() == oth.get_value();
	}

	inline TermKind get_kind() const {
		return INTEGER_LITERAL;
	}

private:
	friend class TermFactoryImpl;
	IntegerLiteralImpl(Locus the_loc, eint_t the_value, pTerm the_type);
	eint_t const value_;
};


class FloatLiteralImpl : public IFloatLiteral, public TermImpl {
public:
	inline virtual eint_t get_significand() const {
		return significand_;
	}
	inline virtual eint_t get_exponent() const {
		return exponent_;
	}
	inline virtual uint8_t get_radix() const {
		return radix_;
	}
	inline virtual bool is_constant() const {
		return true;
	}
	virtual std::string to_string() const;

	inline bool is_equal(ITerm const& other) const {
		// TODO Really should check the computed values somehow.
		auto oth = dynamic_cast<FloatLiteralImpl const&>(other);
		return (get_significand() == oth.get_significand()) &&
				(get_exponent() == oth.get_exponent()) &&
				(get_radix() == oth.get_radix());
	}

	inline TermKind get_kind() const {
		return FLOAT_LITERAL;
	}

private:
	friend class TermFactoryImpl;
	FloatLiteralImpl(Locus the_loc, eint_t the_significand, eint_t the_exponent,
			uint8_t the_radix, pTerm the_type);
	eint_t const significand_;
	eint_t const exponent_;
	uint8_t const radix_;
};


class BitStringLiteralImpl : public IBitStringLiteral, public TermImpl {
public:
	inline virtual eint_t get_bits() const {
		return bits_;
	}
	inline virtual eint_t get_length() const {
		return length_;
	}
	inline virtual bool is_constant() const {
		return true;
	}
	virtual std::string to_string() const;

	inline bool is_equal(ITerm const& other) const {
		auto oth = dynamic_cast<BitStringLiteralImpl const&>(other);
		return (get_bits() == oth.get_bits()) &&
				(get_length() == oth.get_length());
	}

	inline TermKind get_kind() const {
		return BIT_STRING_LITERAL;
	}

private:
	friend class TermFactoryImpl;
	BitStringLiteralImpl(Locus the_loc, eint_t the_bits, eint_t the_length,
			pTerm the_type);
	eint_t const bits_;
	eint_t const length_;
};


class BooleanLiteralImpl : public IBooleanLiteral, public TermImpl {
public:
	inline virtual bool get_value() const {
		return value_;
	}
	inline virtual bool is_constant() const {
		return true;
	}
	virtual std::string to_string() const;

	inline bool is_equal(ITerm const& other) const {
		auto oth = dynamic_cast<BooleanLiteralImpl const&>(other);
		return get_value() == oth.get_value();
	}

	inline TermKind get_kind() const {
		return BOOLEAN_LITERAL;
	}

private:
	friend class TermFactoryImpl;
	BooleanLiteralImpl(Locus the_loc, bool value, pTerm the_type);
	bool const value_;
};

} /* namespace basic */
} /* namespace term */
} /* namespace elision */

#endif /* LITERAL_H_ */