#ifndef IAPPLY_H_
#define IAPPLY_H_

/**
 * @file
 * Define the structure of an apply.
 *
 * @author sprowell@gmail.com
 *
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

#include "ITerm.h"

namespace elision {
namespace term {

/**
 * Define the public interface to an apply instance.  An apply consists of two
 * terms; a left term called the @b operator, and a right term called the
 * @b argument.
 *
 * An apply is constructed when one term is applied to another but no special
 * case applies (such as an operator being applied to an argument).
 */
class IApply : public virtual ITerm {
public:
	/**
	 * Get the operator.
	 * @return The operator.
	 */
	virtual pTerm get_operator() const = 0;

	/**
	 * Get the argument.
	 * @return The argument.
	 */
	virtual pTerm get_argument() const = 0;
};

/// Shorthand for an apply pointer.
typedef std::shared_ptr<IApply const> pApply;

} /* namespace term */
} /* namespace elision */


#endif /* IAPPLY_H_ */
