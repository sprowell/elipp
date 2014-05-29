#ifndef ELISIONEXCEPTION_H_
#define ELISIONEXCEPTION_H_

/**
 * @file
 * TODO: Describe purpose of file.
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

#include "Loc.h"
#include <string>
#include <boost/optional.hpp>

namespace elision {

/**
 * Define a base class for Elision exceptions.
 */
class ElisionException : std::exception {
public:
	/**
	 * Make a new Elision exception.
	 * @param loc		A relevant location, if any.
	 * @param msg		A human-readable description of what happened.
	 * @param cause	An exception that caused this exception.
	 */
	ElisionException(Loc const& loc, std::string const& msg,
			ElisionException const& cause) :
			loc_(loc), message_(msg) {
		cause_.reset(cause);
	}

	/**
	 * Make a new Elision exception.
	 * @param loc		A relevant location, if any.
	 * @param msg		A human-readable description of what happened.
	 */
	ElisionException(Loc const& loc, std::string const& msg) :
			loc_(loc), message_(msg) {
	}

	/**
	 * Make a new Elision exception.  The location is assumed to be internal.
	 * @param msg		A human-readable description of what happened.
	 */
	ElisionException(std::string const& msg) :
			loc_(Loc::get_internal()), message_(msg) {
	}

	 /// Deallocate this instance.
	 ~ElisionException() = default;

	 /**
	  * Get the human-readable message stored in this exception.
	  * @return	The message.
	  */
	 std::string const& get_message() const;

	 /**
	  * Get the prior exception that caused this exception, if any.
	  * @return	The prior exception, if any.
	  */
	 boost::optional<ElisionException const&> const& get_cause() const {
		 return cause_;
	 }

	 /**
	  * See if this exception has a cause.
	  * @return	True if this exception has a specified cause.
	  */
	 bool has_cause() const {
		 return cause_.is_initialized();
	 }

	 /**
	  * Get the location associated with this exception.
	  * @return	The location associated with this exception.
	  */
	 Loc const& get_loc() const;

private:
	 Loc const& loc_;
	 std::string const& message_;
	 boost::optional<ElisionException const&> cause_;
};

} /* namespace elision */

#endif /* ELISIONEXCEPTION_H_ */