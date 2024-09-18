#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestSuite, HandlesEmptyInput) {
    char soundex[5];
    
    generateSoundex("", soundex);  // Empty input
    ASSERT_STREQ(soundex, "");
}

TEST(SoundexTestSuite, HandlesSingleConsonant) {
    char soundex[5];
    
    generateSoundex("B", soundex);  // Single consonant
    ASSERT_STREQ(soundex, "B000");
}

TEST(SoundexTestSuite, HandlesOnlyVowels) {
    char soundex[5];
    
    generateSoundex("AEIOU", soundex);  // Only vowels
    ASSERT_STREQ(soundex, "A000");
}

TEST(SoundexTestSuite, IgnoresCaseDifferences) {
    char soundex[5];

    generateSoundex("Smith", soundex);  // Mixed case input
    ASSERT_STREQ(soundex, "S530");

    generateSoundex("sMiTh", soundex);  // Different case, same expected result
    ASSERT_STREQ(soundex, "S530");
}

TEST(SoundexTestSuite, HandlesRepeatedConsonants) {
    char soundex[5];
    
    generateSoundex("Bbbb", soundex);  // Repeated consonants
    ASSERT_STREQ(soundex, "B100");

    generateSoundex("Ddddd", soundex);  // Another repeated consonant
    ASSERT_STREQ(soundex, "D300");
}

TEST(SoundexTestSuite, HandlesSpecialCharacters) {
    char soundex[5];
    
    generateSoundex("D#o&g", soundex);  // Special characters in the name
    ASSERT_STREQ(soundex, "D020");
}

TEST(SoundexTestSuite, TruncatesLongNames) {
    char soundex[5];
    
    generateSoundex("Washington", soundex);  // Name longer than 4 characters
    ASSERT_STREQ(soundex, "W252");

    generateSoundex("Gutierrez", soundex);  // Another long name
    ASSERT_STREQ(soundex, "G362");
}

TEST(SoundexTestSuite, HandlesNameWithMultipleZeroMappedLetters) {
    char soundex[5];
    
    generateSoundex("Ashcraft", soundex);  // 'H' and 'C' get mapped to zero
    ASSERT_STREQ(soundex, "A261");
}

TEST(SoundexTestSuite, PadsShortNamesWithZeros) {
    char soundex[5];
    
    generateSoundex("Li", soundex);  // Short name, needs padding
    ASSERT_STREQ(soundex, "L000");

    generateSoundex("Ga", soundex);  // Another short name
    ASSERT_STREQ(soundex, "G000");
}

TEST(SoundexTestSuite, HandlesEdgeCasesWithMixedZeroMappingAndDuplicates) {
    char soundex[5];
    
    generateSoundex("Pfister", soundex);  // Contains characters like 'P' and 'F'
    ASSERT_STREQ(soundex, "P236");

    generateSoundex("Honeyman", soundex);  // Handles names with 'H' and 'Y' mapped to 0
    ASSERT_STREQ(soundex, "H555");
}
