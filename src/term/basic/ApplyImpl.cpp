/**
 * @file
 * Provide an implementation of an apply.
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

#include <basic/ApplyImpl.h>

namespace elision {
namespace term {
namespace basic {

ApplyImpl::ApplyImpl(Locus the_loc, pTerm the_operator, pTerm the_argument,
		pTerm the_type) : TermImpl(the_loc, the_type),
				operator_(the_operator),
				argument_(the_argument) {
	constant_ = [this]() {
		return this->operator_->is_constant() &&
			this->argument_->is_constant();
	};
	strval_ = [this]() {
		return this->operator_->to_string() + "." +
			this->argument_->to_string();
	};
	hash_ = [this]() {
		return hash_combine(argument_, operator_);
	};
	other_hash_ = [this]() {
		return other_hash_combine(operator_, argument_);
	};
	depth_ = [this, the_type]() {
		depth_type depth = std::max(operator_->get_depth(),
				argument_->get_depth());
		return std::max(depth, the_type->get_depth()) + 1;
	};
}


} /* namespace basic */
} /* namespace term */
} /* namespace elision */
