/*
** ansicolours.h for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:24:26 2008 jean-philippe rey
** Last update Fri May 16 21:24:27 2008 jean-philippe rey
*/

#define CSI "\033[" /* Control Sequence Introducer */

/* Font type */
#define STANDARD CSI "0m" /* Reset to default */
#define BOLD CSI "1m"
#define NOBOLD CSI "21m"
#define FAINT CSI "2m"
#define NOFAINT CSI "22m"
#define ITALIC CSI "3m"
#define NOITALIC CSI "23m"
#define UNDERLINE CSI "4m"
#define NOUNDERLINE CSI "24m"
#define FLASH CSI "5m"
#define NOFLASH CSI "25m"
#define MASK CSI "7m"
#define NOMASK CSI "27m"
#define HIDDEN CSI "8m"
#define NOHIDDEN CSI "28m"
#define STRIKE_THROUGH CSI "9m"
#define NOSTRIKE_THROUGH CSI "29m"

/* Font selection */
#define DEFFONT CSI "10m" /* Default font */
#define ALTFONT1 CSI "11m" /* Alternative fonts */
#define ALTFONT2 CSI "12m"
#define ALTFONT3 CSI "13m"
#define ALTFONT4 CSI "14m"
#define ALTFONT5 CSI "15m"
#define ALTFONT6 CSI "16m"
#define ALTFONT7 CSI "17m"
#define ALTFONT8 CSI "18m"
#define ALTFONT9 CSI "19m"
#define FRAKTURFONT CSI "20m" /* Fraktur (Gothic) */

/* Foreground colors */
#define FBLACK CSI "30m"
#define FRED CSI "31m"
#define FGREEN CSI "32m"
#define FYELLOW CSI "33m"
#define FBLUE CSI "34m"
#define FMAGENTA CSI "35m"
#define FCYAN CSI "36m"
#define FWHITE CSI "37m"
#define FDEFAULT CSI "39m"
#define FBRIGHT_BLACK CSI "90m"
#define FBRIGHT_RED CSI "91m"
#define FBRIGHT_GREEN CSI "92m"
#define FBRIGHT_YELLOW CSI "93m"
#define FBRIGHT_BLUE CSI "94m"
#define FBRIGHT_MAGENTA CSI "95m"
#define FBRIGHT_CYAN CSI "96m"
#define FBRIGHT_WHITE CSI "97m"

/* Background colors */
#define BBLACK CSI "40m"
#define BRED CSI "41m"
#define BGREEN CSI "42m"
#define BYELLOW CSI "43m"
#define BBLUE CSI "44m"
#define BMAGENTA CSI "45m"
#define BCYAN CSI "46m"
#define BWHITE CSI "47m"
#define BDEFAULT CSI "49m"
#define BBRIGHT_BLACK CSI "100m"
#define BBRIGHT_RED CSI "101m"
#define BBRIGHT_GREEN CSI "102m"
#define BBRIGHT_YELLOW CSI "103m"
#define BBRIGHT_BLUE CSI "104m"
#define BBRIGHT_MAGENTA CSI "105m"
#define BBRIGHT_CYAN CSI "106m"
#define BBRIGHT_WHITE CSI "107m"

#define RESET_TERM CSI "c"

#define CLEAR_SCREEN CSI "2J"
#define CLEAR_LINE CSI "K"

#define SAVE_CUR_POS CSI "7"
#define RESTORE_CUR_POS CSI "8"

#define LOCATE(x, y) CSI #x";"#y"H"
