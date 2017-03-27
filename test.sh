#!/bin/sh

COL="\033[;35m";
COL2="\033[;92m";
ESC="\033[33;0m";

n=1
M1="OK no sort 8";
ARG1="1 2 5 897 5432 6467";

M2="WRONG dub";
ARG2="-1 2 5 897 5432 6467 -1";

#{
#	while[$n -le 2]
#		echo "${COL2} ${M${n}} ${ESC}"
#		echo "${ARG${n}}"
#		echo ------------------------------------------------------------
#		./push_swap ${ARG${n}}
#		echo "------------------------------------------------------------\n"
#		(( n=n+1 ))
#}

echo "${COL2}ok 500 ${ESC}"
echo ------------------------------------------------------------
./push_swap -268 -117 -966 -539 -158 -593 -817 -407 -952 -728 -922 -811 -443 -839 -195 -927 -139 -282 -563 -999 -715 -369 -699 -807 -465 -464 -463 -97 -131 -624 -659 -294 -329 -636 -1 -756 -261 -596 -411 -538 -541 -466 -904 -814 -707 -579 -59 -889 -531 -45 -169 -767 -201 -96 -901 -112 -254 -412 0 -896 -597 -643 -848 -850 -234 -10 -124 -739 -958 -203 -223 -82 -586 -808 -4 -744 -422 -260 -103 -19 -906 -680 -926 -921 -256 -332 -287 -932 -672 -13 -782 -556 -50 -398 -629 -681 -154 -292 -469 -931 -137 -992 -675 -457 -340 -46 -36 -803 -130 -377 -588 -42 -693 -319 -376 -225 -197 -481 -237 -291 -176 -870 -696 -15 -704 -956 -233 -726 -694 -241 -535 -193 -690 -540 -275 -456 -536 -228 -39 -775 -812 -866 -107 -101 -497 -186 -977 -418 -482 -323 -48 -441 -179 -774 -740 -379 -475 -949 -145 -213 -755 -750 -613 -761 -642 -537 -729 -800 -165 -655 -937 -390 -350 -635 -52 -708 -153 -975 -277 -296 -276 -731 -637 -529 -584 -503 -801 -78 -152 -971 -718 -594 -60 -144 -658 -449 -962 -990 -433 -711 -232 -561 -845 -863 -267 -968 -984 -644 -310 -969 -616 -705 -781 -722 -660 -120 -170 -793 -108 -382 -414 -91 -68 -825 -533 -401 -357 -852 -255 -408 -843 -885 -58 -853 -138 -98 -930 -316 -562 -172 -307 -874 -510 -163 -406 -856 -548 -522 -318 -578 -899 -392 -168 -890 -753 -171 -373 -621 -21 -924 -9 -979 -508 -487 -189 -833 -592 -502 -770 -127 -855 -72 -81 -679 -790 -113 -960 -963 -574 -183 -582 -434 -285 -31 -585 -587 -281 -180 -809 -320 -66 -55 -83 -645 -876 -871 -492 -119 -105 -837 -551 -290 -555 -665 -689 -26 -663 -569 -829 -520 -393 -34 -857 -343 -886 -327 -768 -989 -2 -399 -214 -656 -878 -600 -532 -167 -657 -240 -799 -182 -662 -873 -917 -742 -177 -460 -961 -498 1 -544 -630 -765 -86 -149 -844 -888 -815 -709 -359 -605 -484 -685 -430 -283 -84 -900 -455 -632 -955 -902 -370 -916 -859 -785 -759 -836 -93 -736 -858 -738 -819 -448 -909 -238 -628 -402 -56 -470 -495 -664 -8 -194 -713 -210 -777 -590 -938 -527 -501 -142 -159 -571 -395 -118 -823 -226 -965 -447 -133 -661 -816 -129 -821 -747 -63 -334 -911 -354 -205 -987 -951 -925 -710 -288 -530 -453 -258 -892 -426 -923 -861 -161 -734 -304 -204 -565 -271 -500 -618 -79 -834 -190 -991 -648 -822 -832 -239 -918 -366 -236 -438 -818 -65 -389 -136 -604 -90 -284 -125 -368 -297 -5 -940 -262 -121 -724 -947 -317 -654 -511 -907 -29 -345 -242 -489 -897 -568 -1000 -589 -534 -676 -23 -773 -957 -305 -840 -543 -758 -974 -416 -388 -76 -633 -272 -274 -805 -99 -506 -386 -400 -166 -716 -806 -428 -691 -451 -328 -37 -361 -519
echo "\n------------------------------------------------------------\n"

echo "${COL2}OK 100${ESC}"
echo ------------------------------------------------------------
./push_swap -353 -411 -318 -61 -122 89 83 43 -776 -609 -579 423 855 -832 139 233 578 206 -383 -730 776 -30 -919 676 728 -257 483 346 -281 965 143 -261 713 -280 -797 269 -817 469 509 349 240 214 -753 -608 -214 -90 246 559 704 -733 -312 381 -22 635 -304 572 81 -846 -977 464 -282 85 885 -445 -869 -747 62 -134 522 -54 -518 -402 915 810 -254 -881 853 -24 -520 -189 861 165 142 -116 380 872 -236 962 -47 -783 -562 -678 565 -453 -3 -153 649 -696 -284 865
echo "\n------------------------------------------------------------\n"

echo "${COL2}OK 6${ESC}"
echo "1 -2 5 897 5432 6467"
echo ------------------------------------------------------------
./push_swap 1 -2 5 897 5432 6467
echo "------------------------------------------------------------\n"

echo "${COL2}OK no sort 7${ESC}"
echo ------------------------------------------------------------
./push_swap 1 2 5 897 5432 6467 7000
echo "------------------------------------------------------------\n"

echo "${COL2}OK no sort 11${ESC}"
echo ------------------------------------------------------------
./push_swap -974 -633 -416 -388 -76 1 2 5 897 5432 6467
echo "------------------------------------------------------------\n"

echo "${COL2}OK no sort min max int${ESC}"
echo ------------------------------------------------------------
./push_swap -2147483648 -974 -633 -416 -388 -76 1 2 5 897 5432 6467 2147483647
echo "------------------------------------------------------------\n"

echo "${COL2}OK no sort one number${ESC}"
echo ------------------------------------------------------------
./push_swap -974
echo "------------------------------------------------------------\n"

echo "${COL}WRONG 500${ESC}"
echo ------------------------------------------------------------
./push_swap -117 -966 -539 -158 -593 -817 -407 -952 -728 -922 -811 -443 -839 -195 -927 -139 -282 -563 -999 -715 -369 -699 -807 -465 -464 -463 -97 -131 -624 -659 -294 -329 -636 -1 -756 -261 -596 -411 -538 -541 -466 -904 -814 -707 -579 -59 -889 -531 -45 -169 -767 -201 -96 -901 -112 -254 -412 0 -896 -597 -643 -848 -850 -234 -10 -124 -739 -958 -203 -223 -82 -586 -808 -4 -744 -422 -260 -103 -19 -906 -680 -926 -921 -256 -332 -287 -932 -672 -13 -782 -556 -50 -398 -629 -681 -154 -292 -469 -931 -137 -992 -675 -457 -340 -46 -36 -803 -130 -377 -588 -42 -693 -319 -376 -225 -197 -481 -237 -291 -176 -870 -696 -15 -704 -956 -233 -726 -694 -241 -535 -193 -690 -540 -275 -456 -536 -228 -39 -775 -812 -866 -107 -101 -497 -186 -977 -418 -482 -323 -48 -441 -179 -774 -740 -379 -475 -949 -145 -213 -755 -750 -613 -761 -642 -537 -729 -800 -165 -655 -937 -390 -350 -635 -52 -708 -153 -975 -277 -296 -276 -731 -637 -529 -584 -503 -801 -78 -152 -971 -718 -594 -60 -144 -658 -449 -962 -990 -433 -711 -232 -561 -845 -863 -267 -968 -984 -644 -310 -969 -616 -705 -781 -722 -660 -120 -170 -793 -108 -382 -414 -91 -68 -825 -533 -401 -357 -852 -255 -408 -843 -885 -58 -853 -138 -98 -930 -316 -562 -172 -307 -874 -510 -163 -406 -856 -548 -522 -318 -578 -899 -392 -168 -890 -753 -171 -373 -621 -21 -924 -9 -979 -508 -487 -189 -833 -592 -502 -770 -127 -855 -72 -81 -679 -790 -113 -960 -963 -574 -183 -582 -434 -285 -31 -585 -587 -281 -180 -809 -320 -66 -55 -83 -645 -876 -871 -492 -119 -105 -837 -551 -290 -555 -665 -689 -26 -663 -569 -829 -520 -393 -34 -857 -343 -886 -327 -768 -989 -2 -399 -214 -656 -878 -600 -532 -167 -657 -240 -799 -182 -662 -873 -917 -742 -177 -460 -961 -498 1 -544 -630 -765 -86 -149 -844 -888 -815 -709 -359 -605 -484 -685 -430 -283 -84 -900 -455 -632 -955 -902 -370 -916 -859 -785 -759 -836 -93 -736 -858 -738 -819 -448 -909 -238 -628 -402 -56 -470 -495 -664 -8 -194 -713 -210 -777 -590 -938 -527 -501 -142 -159 -571 -395 -118 -823 -226 -965 -447 -133 -661 -816 -129 -821 -747 -63 -334 -911 -354 -205 -987 -951 -925 -710 -288 -530 -453 -258 -892 -426 -923 -861 -161 -734 -304 -204 -565 -271 -500 -618 -79 -834 -190 -991 -648 -822 -832 -239 -918 -366 -236 -438 -818 -65 -389 -136 -604 -90 -284 -125 -368 -297 -5 -940 -262 -121 -724 -947 -317 -654 -511 -907 -29 -345 -242 -489 -897 -568 -1000 -589 -534 -676 -23 -773 -957 -305 -840 -543 -758 -974 -416 -388 -76 -633 -272 -274 -805 -99 -506 -386 -400 -166 -716 -806 -428 -691 -451 -328 -37 -361 -519 -4
echo "------------------------------------------------------------\n"

echo "${COL}WRONG dub${ESC}"
echo ------------------------------------------------------------
./push_swap -7 -8 -807 -807
echo "------------------------------------------------------------\n"

echo "${COL}WRONG symb${ESC}"
echo ------------------------------------------------------------
./push_swap -7 -8 -807 -
echo "------------------------------------------------------------\n"

echo "${COL}WRONG symb${ESC}"
echo ------------------------------------------------------------
./push_swap -7 -8 -807 u
echo "------------------------------------------------------------\n"

echo "${COL}WRONG symb${ESC}"
echo ------------------------------------------------------------
./push_swap jfdslkfj -7 -8 -807 u
echo "------------------------------------------------------------\n"

echo "${COL}WRONG symb${ESC}"
echo ------------------------------------------------------------
./push_swap --7 -8 -807 u
echo "------------------------------------------------------------\n"

echo "${COL}WRONG big num${ESC}"
echo ------------------------------------------------------------
./push_swap -7 -8 -807 -8075489370254387258493275
echo "------------------------------------------------------------\n"

echo "${COL}USAGE${ESC}"
echo ------------------------------------------------------------
./push_swap
echo "------------------------------------------------------------\n"
