#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <unistd.h>

int genererAleatoire(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

void ball1Frame1(){
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "   *****   \n"
           "  *     *   \n"
           " *********    *****      *****    \n"
           "             *     *    *     *   \n"
           "     O      *********  *********  \n");
    usleep(300000);
}

void ball1Frame2(){
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "           \n"
           "   *****   \n"
           "  *     *     *****      *****   \n"
           " *********   *     *    *     *  \n"
           "     O      *********  ********* \n");
    usleep(300000);
}

void ballFrame3(){
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "           \n"
           "           \n"
           "   *****      *****      *****   \n"
           "  *     *    *     *    *     *  \n"
           " *********  *********  ********* \n");
    usleep(300000);
}

void ball2Frame1(){
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "              *****              \n"
           "             *     *             \n"
           "   *****    *********    *****   \n"
           "  *     *               *     *  \n"
           " *********      O      ********* \n");
    usleep(300000);
}

void ball2Frame2(){
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "                                 \n"
           "              *****              \n"
           "   *****     *     *     *****   \n"
           "  *     *   *********   *     *  \n"
           " *********      O      ********* \n");
    usleep(300000);
}

void ball3Frame1(){
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "                         *****   \n"
           "                        *     *  \n"
           "   *****      *****    ********* \n"
           "  *     *    *     *             \n"
           " *********  *********      O     \n");
    usleep(300000);
}

void ball3Frame2(){
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "                                 \n"
           "                         *****   \n"
           "   *****      *****     *     *  \n"
           "  *     *    *     *   ********* \n"
           " *********  *********      O     \n");
    usleep(300000);
}

void afficherFrame1() {
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "           \n"
           "           \n"
           "   *****      *****      *****   \n"
           "  *     *    *     *    *     *  \n"
           " *********  *********  ********* \n");
    usleep(00000);
}

void afficherFrame2() {
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "           \n"
           "   *****   \n"
           "  *     *     *****      *****   \n"
           " *********   *     *    *     *  \n"
           "            *********  ********* \n");
    usleep(00000);
}

void afficherFrame3() {
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "   *****   \n"
           "  *     *   \n"
           " *********    *****      *****    \n"
           "             *     *    *     *   \n"
           "            *********  *********  \n");
    usleep(00000);
}

void afficherFrame4() {
    system("cls");
    printf("\n"
           "           \n"
           "   *****   \n"
           "  *     *  \n"
           " *********  \n"
           "              *****      *****    \n"
           "             *     *    *     *   \n"
           "            *********  *********  \n");
    usleep(00000);
}

void afficherFrame5() {
    system("cls");
    printf("\n"
           "   *****   \n"
           "  *     *  \n"
           " *********  \n"
           "              \n"
           "              *****      *****    \n"
           "             *     *    *     *   \n"
           "            *********  *********  \n");
    usleep(00000);
}

void afficherFrame6() {
    system("cls");
    printf("\n"
           "    *****   \n"
           "   *     *  \n"
           "  ********* \n"
           "              \n"
           "             *****       *****    \n"
           "            *     *     *     *   \n"
           "           *********   *********  \n");
    usleep(00000);
}

void afficherFrame7() {
    system("cls");
    printf("\n"
           "     *****   \n"
           "    *     *  \n"
           "   ********* \n"
           "              \n"
           "            *****        *****    \n"
           "           *     *      *     *   \n"
           "          *********    *********  \n");
    usleep(00000);
}

void afficherFrame8() {
    system("cls");
    printf("\n"
           "       *****                     \n"
           "      *     *                    \n"
           "     *********                   \n"
           "              \n"
           "           *****         *****    \n"
           "          *     *       *     *   \n"
           "         *********     *********  \n");
    usleep(00000);
}

void afficherFrame9() {
    system("cls");
    printf("\n"
           "        *****                    \n"
           "       *     *                   \n"
           "      *********                  \n"
           "              \n"
           "          *****          *****    \n"
           "         *     *        *     *   \n"
           "        *********      *********  \n");
    usleep(00000);
}

void afficherFrame10() {
    system("cls");
    printf("\n"
           "         *****                   \n"
           "        *     *                  \n"
           "       *********                 \n"
           "              \n"
           "         *****           *****    \n"
           "        *     *         *     *   \n"
           "       *********       *********  \n");
    usleep(00000);
}

void afficherFrame11() {
    system("cls");
    printf("\n"
           "          *****                  \n"
           "         *     *                 \n"
           "        *********                \n"
           "              \n"
           "        *****            *****    \n"
           "       *     *          *     *   \n"
           "      *********        *********  \n");
    usleep(00000);
}

void afficherFrame12() {
    system("cls");
    printf("\n"
           "           *****                 \n"
           "          *     *                \n"
           "         *********               \n"
           "              \n"
           "       *****             *****    \n"
           "      *     *           *     *   \n"
           "     *********         *********  \n");
    usleep(00000);
}

void afficherFrame13() {
    system("cls");
    printf("\n"
           "            *****                \n"
           "           *     *               \n"
           "          *********              \n"
           "              \n"
           "      *****              *****    \n"
           "     *     *            *     *   \n"
           "    *********          *********  \n");
    usleep(00000);
}

void afficherFrame14() {
    system("cls");
    printf("\n"
           "             *****               \n"
           "            *     *              \n"
           "           *********             \n"
           "              \n"
           "     *****               *****    \n"
           "    *     *             *     *   \n"
           "   *********           *********  \n");
    usleep(00000);
}

void afficherFrame15() {
    system("cls");
    printf("\n"
           "              *****               \n"
           "             *     *              \n"
           "            *********             \n"
           "              \n"
           "    *****                *****    \n"
           "   *     *              *     *   \n"
           "  *********            *********  \n");
    usleep(00000);
}

void afficherFrame16() {
    system("cls");
    printf("\n"
           "              *****               \n"
           "             *     *              \n"
           "            *********             \n"
           "              \n"
           "   *****                 *****    \n"
           "  *     *               *     *   \n"
           " *********             *********  \n");
    usleep(00000);
}

void afficherFrame17() {
    system("cls");
    printf("\n"
           "             \n"
           "              *****               \n"
           "             *     *              \n"
           "            *********               \n"
           "   *****                 *****    \n"
           "  *     *               *     *   \n"
           " *********             *********  \n");
    usleep(00000);
}

void afficherFrame18() {
    system("cls");
    printf("\n"
           "             \n"
           "            \n"
           "              *****               \n"
           "             *     *                \n"
           "   *****    *********    *****    \n"
           "  *     *               *     *   \n"
           " *********             *********  \n");
    usleep(00000);
}

void afficherFrame19() {
    system("cls");
    printf("\n"
           "             \n"
           "            \n"
           "            \n"
           "              *****                 \n"
           "   *****     *     *     *****    \n"
           "  *     *   *********   *     *   \n"
           " *********             *********  \n");
    usleep(00000);
}

void afficherFrame20() {
    system("cls");
    printf("\n"
           "             \n"
           "            \n"
           "            \n"
           "            \n"
           "   *****      *****      *****    \n"
           "  *     *    *     *    *     *   \n"
           " *********  *********  *********  \n");
    usleep(00000);
}

void afficherFrame21() {
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "           \n"
           "           \n"
           "   *****      *****      *****   \n"
           "  *     *    *     *    *     *  \n"
           " *********  *********  ********* \n");
    usleep(00000);
}

void afficherFrame22() {
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "           \n"
           "   *****   \n"
           "  *     *     *****      *****   \n"
           " *********   *     *    *     *  \n"
           "            *********  ********* \n");
    usleep(00000);
}

void afficherFrame23() {
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "   *****   \n"
           "  *     *   \n"
           " *********    *****      *****    \n"
           "             *     *    *     *   \n"
           "            *********  *********  \n");
    usleep(00000);
}

void afficherFrame24() {
    system("cls");
    printf("\n"
           "           \n"
           "   *****   \n"
           "  *     *  \n"
           " *********  \n"
           "              *****      *****    \n"
           "             *     *    *     *   \n"
           "            *********  *********  \n");
    usleep(00000);
}

void afficherFrame25() {
    system("cls");
    printf("\n"
           "   *****   \n"
           "  *     *  \n"
           " *********  \n"
           "              \n"
           "              *****      *****    \n"
           "             *     *    *     *   \n"
           "            *********  *********  \n");
    usleep(00000);
}

void afficherFrame26() {
    system("cls");
    printf("\n"
           "     *****   \n"
           "    *     *  \n"
           "   *********  \n"
           "              \n"
           "             *****      *****    \n"
           "            *     *    *     *   \n"
           "           *********  *********  \n");
    usleep(00000);
}

void afficherFrame27() {
    system("cls");
    printf("\n"
           "       *****   \n"
           "      *     *  \n"
           "     *********  \n"
           "              \n"
           "            *****      *****    \n"
           "           *     *    *     *   \n"
           "          *********  *********  \n");
    usleep(00000);
}

void afficherFrame28() {
    system("cls");
    printf("\n"
           "         *****   \n"
           "        *     *  \n"
           "       *********  \n"
           "              \n"
           "           *****      *****    \n"
           "          *     *    *     *   \n"
           "         *********  *********  \n");
    usleep(00000);
}

void afficherFrame29() {
    system("cls");
    printf("\n"
           "           *****   \n"
           "          *     *  \n"
           "         *********  \n"
           "              \n"
           "          *****      *****    \n"
           "         *     *    *     *   \n"
           "        *********  *********  \n");
    usleep(00000);
}

void afficherFrame30() {
    system("cls");
    printf("\n"
           "             *****   \n"
           "            *     *  \n"
           "           *********  \n"
           "              \n"
           "         *****      *****    \n"
           "        *     *    *     *   \n"
           "       *********  *********  \n");
    usleep(00000);
}

void afficherFrame31() {
    system("cls");
    printf("\n"
           "               *****   \n"
           "              *     *  \n"
           "             *********  \n"
           "              \n"
           "        *****      *****    \n"
           "       *     *    *     *   \n"
           "      *********  *********  \n");
    usleep(00000);
}

void afficherFrame32() {
    system("cls");
    printf("\n"
           "                 *****   \n"
           "                *     *  \n"
           "               ********* \n"
           "              \n"
           "       *****      *****    \n"
           "      *     *    *     *   \n"
           "     *********  *********  \n");
    usleep(00000);
}

void afficherFrame33() {
    system("cls");
    printf("\n"
           "                   *****       \n"
           "                  *     *      \n"
           "                 *********     \n"
           "              \n"
           "      *****      *****    \n"
           "     *     *    *     *   \n"
           "    *********  *********  \n");
    usleep(00000);
}

void afficherFrame34() {
    system("cls");
    printf("\n"
           "                     *****      \n"
           "                    *     *     \n"
           "                   *********    \n"
           "              \n"
           "     *****      *****    \n"
           "    *     *    *     *   \n"
           "   *********  *********  \n");
    usleep(00000);
}

void afficherFrame35() {
    system("cls");
    printf("\n"
           "                       *****       \n"
           "                      *     *      \n"
           "                     *********     \n"
           "              \n"
           "    *****      *****    \n"
           "   *     *    *     *   \n"
           "  *********  *********  \n");
    usleep(00000);
}

void afficherFrame36() {
    system("cls");
    printf("\n"
           "                         *****     \n"
           "                        *     *    \n"
           "                       *********   \n"
           "             \n"
           "   *****      *****                \n"
           "  *     *    *     *               \n"
           " *********  *********              \n");
    usleep(00000);
}

void afficherFrame37() {
    system("cls");
    printf("\n"
           "        \n"
           "                         *****     \n"
           "                        *     *    \n"
           "                       *********   \n"
           "   *****      *****                \n"
           "  *     *    *     *               \n"
           " *********  *********              \n");
    usleep(00000);
}

void afficherFrame38() {
    system("cls");
    printf("\n"
           "        \n"
           "        \n"
           "                         *****     \n"
           "                        *     *    \n"
           "   *****      *****    *********   \n"
           "  *     *    *     *               \n"
           " *********  *********              \n");
    usleep(00000);
}

void afficherFrame39() {
    system("cls");
    printf("\n"
           "        \n"
           "        \n"
           "        \n"
           "                         *****     \n"
           "   *****      *****     *     *    \n"
           "  *     *    *     *   *********   \n"
           " *********  *********              \n");
    usleep(00000);
}

void afficherFrame40() {
    system("cls");
    printf("\n"
           "        \n"
           "        \n"
           "        \n"
           "        \n"
           "   *****      *****      *****     \n"
           "  *     *    *     *    *     *    \n"
           " *********  *********  *********   \n");
    usleep(00000);
}

void afficherFrame41() {
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "           \n"
           "           \n"
           "   *****      *****      *****   \n"
           "  *     *    *     *    *     *  \n"
           " *********  *********  ********* \n");
    usleep(00000);
}

void afficherFrame42() {
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "           \n"
           "              *****               \n"
           "   *****     *     *     *****     \n"
           "  *     *   *********   *     *    \n"
           " *********             *********   \n");
    usleep(00000);
}

void afficherFrame43() {
    system("cls");
    printf("\n"
           "           \n"
           "           \n"
           "              *****                 \n"
           "             *     *                \n"
           "   *****    *********    *****      \n"
           "  *     *               *     *     \n"
           " *********             *********    \n");
    usleep(00000);
}

void afficherFrame44() {
    system("cls");
    printf("\n"
           "           \n"
           "              *****              \n"
           "             *     *             \n"
           "            *********            \n"
           "   *****                 *****      \n"
           "  *     *               *     *     \n"
           " *********             *********    \n");
    usleep(00000);
}

void afficherFrame45() {
    system("cls");
    printf("\n"
           "              *****            \n"
           "             *     *           \n"
           "            *********          \n"
           "              \n"
           "   *****                 *****        \n"
           "  *     *               *     *       \n"
           " *********             *********    \n");
    usleep(00000);
}

void afficherFrame46() {
    system("cls");
    printf("\n"
           "               *****   \n"
           "              *     *  \n"
           "             ********* \n"
           "              \n"
           "   *****                *****          \n"
           "  *     *              *     *        \n"
           " *********            *********    \n");
    usleep(00000);
}

void afficherFrame47() {
    system("cls");
    printf("\n"
           "                *****   \n"
           "               *     *  \n"
           "              ********* \n"
           "              \n"
           "   *****               *****         \n"
           "  *     *             *     *        \n"
           " *********           *********      \n");
    usleep(00000);
}

void afficherFrame48() {
    system("cls");
    printf("\n"
           "                  *****                     \n"
           "                 *     *                    \n"
           "                *********                   \n"
           "              \n"
           "   *****              *****             \n"
           "  *     *            *     *          \n"
           " *********          *********       \n");
    usleep(00000);
}

void afficherFrame49() {
    system("cls");
    printf("\n"
           "                   *****                    \n"
           "                  *     *                   \n"
           "                 *********                  \n"
           "              \n"
           "   *****             *****              \n"
           "  *     *           *     *           \n"
           " *********         *********        \n");
    usleep(00000);
}

void afficherFrame50() {
    system("cls");
    printf("\n"
           "                    *****                   \n"
           "                   *     *                  \n"
           "                  *********                 \n"
           "              \n"
           "   *****            *****               \n"
           "  *     *          *     *            \n"
           " *********        *********         \n");
    usleep(00000);
}

void afficherFrame51() {
    system("cls");
    printf("\n"
           "                     *****                  \n"
           "                    *     *                 \n"
           "                   *********                \n"
           "              \n"
           "   *****           *****                \n"
           "  *     *         *     *             \n"
           " *********       *********          \n");
    usleep(00000);
}

void afficherFrame52() {
    system("cls");
    printf("\n"
           "                      *****                 \n"
           "                     *     *                \n"
           "                    *********               \n"
           "              \n"
           "   *****          *****                 \n"
           "  *     *        *     *              \n"
           " *********      *********           \n");
    usleep(00000);
}

void afficherFrame53() {
    system("cls");
    printf("\n"
           "                       *****                \n"
           "                      *     *               \n"
           "                     *********              \n"
           "              \n"
           "   *****         *****                  \n"
           "  *     *       *     *               \n"
           " *********     *********            \n");
    usleep(00000);
}

void afficherFrame54() {
    system("cls");
    printf("\n"
           "                        *****               \n"
           "                       *     *              \n"
           "                      *********             \n"
           "              \n"
           "   *****        *****                   \n"
           "  *     *      *     *                \n"
           " *********    *********             \n");
    usleep(00000);
}

void afficherFrame55() {
    system("cls");
    printf("\n"
           "                         *****               \n"
           "                        *     *              \n"
           "                       *********             \n"
           "              \n"
           "   *****       *****                    \n"
           "  *     *     *     *                 \n"
           " *********   *********              \n");
    usleep(00000);
}

void afficherFrame56() {
    system("cls");
    printf("\n"
           "                         *****               \n"
           "                        *     *              \n"
           "                       *********             \n"
           "              \n"
           "   *****      *****                    \n"
           "  *     *    *     *                  \n"
           " *********  *********               \n");
    usleep(00000);
}

void afficherFrame57() {
    system("cls");
    printf("\n"
           "             \n"
           "                         *****          \n"
           "                        *     *         \n"
           "                       *********        \n"
           "   *****      *****                     \n"
           "  *     *    *     *                  \n"
           " *********  *********               \n");
    usleep(00000);
}

void afficherFrame58() {
    system("cls");
    printf("\n"
           "             \n"
           "            \n"
           "                         *****               \n"
           "                        *     *                \n"
           "   *****      *****    *********        \n"
           "  *     *    *     *                  \n"
           " *********  *********               \n");
    usleep(00000);
}

void afficherFrame59() {
    system("cls");
    printf("\n"
           "             \n"
           "            \n"
           "            \n"
           "                         *****        \n"
           "   *****      *****     *     *         \n"
           "  *     *    *     *   *********      \n"
           " *********  *********               \n");
    usleep(00000);
}

void afficherFrame60() {
    system("cls");
    printf("\n"
           "             \n"
           "            \n"
           "            \n"
           "            \n"
           "   *****      *****      *****    \n"
           "  *     *    *     *    *     *   \n"
           " *********  *********  *********  \n");
    usleep(00000);
}

void swit1_2(){
    afficherFrame1();
    afficherFrame2();
    afficherFrame3();
    afficherFrame4();
    afficherFrame5();
    afficherFrame6();
    afficherFrame7();
    afficherFrame8();
    afficherFrame9();
    afficherFrame10();
    afficherFrame11();
    afficherFrame12();
    afficherFrame13();
    afficherFrame14();
    afficherFrame15();
    afficherFrame16();
    afficherFrame17();
    afficherFrame18();
    afficherFrame19();
    afficherFrame20();
}

void swit2_1(){
    afficherFrame20();
    afficherFrame19();
    afficherFrame18();
    afficherFrame17();
    afficherFrame16();
    afficherFrame15();
    afficherFrame14();
    afficherFrame13();
    afficherFrame12();
    afficherFrame11();
    afficherFrame10();
    afficherFrame9();
    afficherFrame8();
    afficherFrame7();
    afficherFrame6();
    afficherFrame5();
    afficherFrame4();
    afficherFrame3();
    afficherFrame2();
    afficherFrame1();
}

void swit1_23(){
    afficherFrame21();
    afficherFrame22();
    afficherFrame23();
    afficherFrame24();
    afficherFrame25();
    afficherFrame25();
    afficherFrame26();
    afficherFrame27();
    afficherFrame28();
    afficherFrame29();
    afficherFrame30();
    afficherFrame31();
    afficherFrame32();
    afficherFrame33();
    afficherFrame34();
    afficherFrame35();
    afficherFrame36();
    afficherFrame37();
    afficherFrame38();
    afficherFrame39();
    afficherFrame40();
}

void swit23_1(){
    afficherFrame40();
    afficherFrame39();
    afficherFrame38();
    afficherFrame37();
    afficherFrame36();
    afficherFrame35();
    afficherFrame34();
    afficherFrame33();
    afficherFrame32();
    afficherFrame31();
    afficherFrame30();
    afficherFrame29();
    afficherFrame28();
    afficherFrame27();
    afficherFrame26();
    afficherFrame25();
    afficherFrame24();
    afficherFrame23();
    afficherFrame22();
    afficherFrame21();
}

void swit3_2(){
    afficherFrame60();
    afficherFrame59();
    afficherFrame58();
    afficherFrame57();
    afficherFrame56();
    afficherFrame55();
    afficherFrame54();
    afficherFrame53();
    afficherFrame52();
    afficherFrame51();
    afficherFrame50();
    afficherFrame49();
    afficherFrame48();
    afficherFrame47();
    afficherFrame46();
    afficherFrame45();
    afficherFrame44();
    afficherFrame43();
    afficherFrame42();
    afficherFrame41();
}

void swit2_3(){
    afficherFrame41();
    afficherFrame42();
    afficherFrame43();
    afficherFrame44();
    afficherFrame45();
    afficherFrame46();
    afficherFrame47();
    afficherFrame48();
    afficherFrame49();
    afficherFrame50();
    afficherFrame51();
    afficherFrame52();
    afficherFrame53();
    afficherFrame54();
    afficherFrame55();
    afficherFrame56();
    afficherFrame57();
    afficherFrame58();
    afficherFrame59();
    afficherFrame60();
}

void ball_1(){
    ball1Frame1();
    ball1Frame2();
    ballFrame3();
}

void ball_2(){
    ball2Frame1();
    ball2Frame2();
    ballFrame3();
}

void ball_3(){
    ball3Frame1();
    ball3Frame2();
    ballFrame3();
}

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));
    setlocale(LC_ALL, "");

    int nbr = genererAleatoire(1,3);

    if(nbr==1){
        ball_1();
    }else if(nbr==2){
        ball_2();
    }else if(nbr==3){
        ball_3();
    }

    Sleep(500);

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    swit1_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
    swit23_1();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
    swit2_3();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    swit1_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    swit3_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    swit1_23();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    swit1_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    swit2_3();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    swit1_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    swit2_3();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    swit1_23();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    swit3_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    swit2_1();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    swit3_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    swit1_23();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    swit2_3();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
    swit2_3();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    swit1_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
    swit3_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    swit1_23();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
    swit2_1();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    swit3_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    swit1_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    swit2_3();
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    swit1_23();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    swit3_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    swit1_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    swit2_3();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    swit1_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    swit23_1();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    swit3_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    swit1_23();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    swit1_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    swit23_1();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    swit2_3();
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    swit1_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    swit3_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    swit1_23();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    swit1_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
    swit2_3();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    swit1_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    swit2_3();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    swit1_23();
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    swit3_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    swit2_1();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    swit3_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    swit1_23();
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    swit2_3();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    swit2_3();
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    swit1_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    swit3_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    swit1_23();
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    swit2_1();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    swit3_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    swit1_2();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    printf("\n    \"1\"        \"2\"        \"3\"  ");

    int play;
    printf("\n\nVotre chois : ");
    scanf("%d",&play);

    if(nbr==1){
        ballFrame3();
        ball2Frame2();
        ball2Frame1();
    }else if(nbr==2){
        ballFrame3();
        ball3Frame2();
        ball3Frame1();
    }else if(nbr==3){
        ballFrame3();
        ball1Frame2();
        ball1Frame1();
    }

    if(nbr==1 && play==2){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("\n\nGooooood !!!!\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }else if(nbr==2 && play==3){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("\n\nGooooood !!!!\n\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }else if(nbr==3 && play==1){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("\n\nGooooood !!!!\n\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }else{
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("\n\nYou lose  -_- \n\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }


    return 0;
}




