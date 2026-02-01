#include <stdio.h>
#include <windows.h> // For Beep function

int main() {
    //Song 1

    printf("Playing an enhanced melody...\n");

    // First part: Twinkle, Twinkle, Little Star
    Beep(261, 400); // C
    Beep(261, 400); // C
    Beep(392, 400); // G
    Beep(392, 400); // G
    Beep(440, 400); // A
    Beep(440, 400); // A
    Beep(392, 800); // G (longer)

    Sleep(200); // Pause

    Beep(349, 400); // F
    Beep(349, 400); // F
    Beep(330, 400); // E
    Beep(330, 400); // E
    Beep(294, 400); // D
    Beep(294, 400); // D
    Beep(261, 800); // C (longer)

    Sleep(400); // Longer pause between parts

    // Second part: How I Wonder What You Are
    Beep(392, 400); // G
    Beep(392, 400); // G
    Beep(349, 400); // F
    Beep(349, 400); // F
    Beep(330, 400); // E
    Beep(330, 400); // E
    Beep(294, 800); // D (longer)

    Sleep(200); // Pause

    // Third part: Up Above the World So High
    Beep(392, 400); // G
    Beep(392, 400); // G
    Beep(349, 400); // F
    Beep(349, 400); // F
    Beep(330, 400); // E
    Beep(330, 400); // E
    Beep(294, 800); // D (longer)

    /*
    Sleep(200); // Pause

    // Fourth part: Like a Diamond in the Sky
    Beep(261, 400); // C
    Beep(261, 400); // C
    Beep(392, 400); // G
    Beep(392, 400); // G
    Beep(440, 400); // A
    Beep(440, 400); // A
    Beep(392, 800); // G (longer)

    Sleep(200); // Pause

    // Repeat First part
    Beep(349, 400); // F
    Beep(349, 400); // F
    Beep(330, 400); // E
    Beep(330, 400); // E
    Beep(294, 400); // D
    Beep(294, 400); // D
    Beep(261, 800); // C (longer)
    */

    printf("Enhanced melody finished!\n");

    return 0;
}
