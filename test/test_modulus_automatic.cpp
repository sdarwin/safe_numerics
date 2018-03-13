//  Copyright (c) 2012 Robert Ramey
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <exception>

#include "../include/safe_integer.hpp"
#include "../include/automatic.hpp"

template <class T>
using safe_t = boost::numeric::safe<
    T,
    boost::numeric::automatic
>;

#include "test_modulus.hpp"
#include "test.hpp"
#include "test_values.hpp"

// note: These tables presume that the the size of an int is 32 bits.
// This should be changed for a different architecture or better yet
// be dynamically adjusted depending on the indicated architecture

const char *test_modulus_result[VALUE_ARRAY_SIZE] = {
//      0       0       0       0
//      012345670123456701234567012345672
//      012345678901234567890123456789010
/* 0*/ "................................x",
/* 1*/ "................................x",
/* 2*/ "................................x",
/* 3*/ "................................x",
/* 4*/ "................................x",
/* 5*/ "................................x",
/* 6*/ "................................x",
/* 7*/ "................................x",

/* 8*/ "................................x",
/* 9*/ "................................x",
/*10*/ "................................x",
/*11*/ "................................x",
/*12*/ "................................x",
/*13*/ "................................x",
/*14*/ "................................x",
/*15*/ "................................x",

//      0       0       0       0
//      012345670123456701234567012345672
//      012345678901234567890123456789010
/*16*/ "................................x",
/*17*/ "................................x",
/*18*/ "................................x",
/*19*/ "................................x",
/*20*/ "................................x",
/*21*/ "................................x",
/*22*/ "................................x",
/*23*/ "................................x",

/*24*/ "................................x",
/*25*/ "................................x",
/*26*/ "................................x",
/*27*/ "................................x",
/*28*/ "................................x",
/*29*/ "................................x",
/*30*/ "................................x",
/*31*/ "................................x",
/*32*/ "................................x"
};

#define TEST_IMPL(v1, v2, result) \
    rval &= test_modulus(         \
        v1,                       \
        v2,                       \
        BOOST_PP_STRINGIZE(v1),   \
        BOOST_PP_STRINGIZE(v2),   \
        result                    \
    );
/**/

#define TESTX(value_index1, value_index2)          \
    (std::cout << value_index1 << ',' << value_index2 << ','); \
    TEST_IMPL(                                     \
        BOOST_PP_ARRAY_ELEM(value_index1, VALUES), \
        BOOST_PP_ARRAY_ELEM(value_index2, VALUES), \
        test_modulus_result[value_index1][value_index2] \
    )
/**/

int main(int, char *[]){
    bool rval = true;
    TESTX(1,19)
    // TEST_EACH_VALUE_PAIR
    std::cout << (rval ? "success!" : "failure") << std::endl;
    return ! rval ;
}
