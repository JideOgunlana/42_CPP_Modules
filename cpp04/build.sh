SUB_DIRS="ex00 ex01 ex02"
EX00_EXEC="Polymorphism"
EX01_EXEC="AnimalIdeas"
EX02_EXEC="AbstractClass"

if [ "$1" == "" ]; then
    for DIR in $SUB_DIRS; do
        cd $DIR
        make
        cd ..
    done
fi

if [ "$1" == "clean" ]; then
    for DIR in $SUB_DIRS; do
        cd $DIR
        make clean
        cd ..
    done
fi

if [ "$1" == "fclean" ]; then
    for DIR in $SUB_DIRS; do
        cd $DIR
        make fclean
        cd ..
    done
fi

if [ "$1" == "ex00" ] || [ "$1" == "ex00/" ]; then
    cd "ex00"
    make
    printf "\n"
    ./${EX00_EXEC}
    cd ..
fi

if [ "$1" == "ex01" ] || [ "$1" == "ex01/" ]; then
    cd "ex01"
    make
    printf "\n"
    ./${EX01_EXEC}
    cd ..
fi

if [ "$1" == "ex02" ] || [ "$1" == "ex02/" ]; then
    cd "ex02"
    make
    printf "\n"
    ./${EX02_EXEC}
    cd ..
fi