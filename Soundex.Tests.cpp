#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
 
 generateSoundex("AX", soundex);
 ASSERT_STREQ(soundex,"A200");

 generateSoundex("soundex", soundex);
 ASSERT_STREQ(soundex,"S532");

 generateSoundex("Robbert", soundex);
 ASSERT_STREQ(soundex,"R163");

 generateSoundex("R", soundex);
 ASSERT_STREQ(soundex,"R000");

 generateSoundex("aou", soundex);
 ASSERT_STREQ(soundex,"A000");
 
}
