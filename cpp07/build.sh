SUB_DIRS="ex00 ex01 ex02"
EX00_EXEC="Whatever"
EX01_EXEC="Iter"
EX02_EXEC="Array"
EXECUTABLES=("${EX00_EXEC}" "${EX01_EXEC}" "${EX02_EXEC}")
DIRECTORIES=("ex00" "ex01" "ex02")


# MAKE ALL EXERCISES
if [ "$1" == "" ]; then
    for DIR in ${SUB_DIRS}; do
        cd ${DIR}
        make
        cd ..
    done
fi

# MAKE SPECIFIC EXERCISES
for ((i=0; i<${#DIRECTORIES[@]}; i++)); do
    if [ "$1" == "${DIRECTORIES[i]}" ] || [ "$1" == "${DIRECTORIES[i]}/" ]; then
        cd "${DIRECTORIES[i]}"
        make
        printf "\n"
        ./"${EXECUTABLES[i]}"
        printf "$3"
        cd ..
        break
    fi
done

# CLEAN
if [ "$1" == "clean" ]; then
    if [ "$2" == "ex00" ] || [ "$2" == "ex00/" ]; then
        cd "ex00"
        make clean;
        cd ..
    elif [ "$2" == "ex01" ] || [ "$2" == "ex01/" ]; then
        cd "ex01"
        make clean;
        cd ..
    elif [ "$2" == "ex02" ] || [ "$2" == "ex02/" ]; then
        cd "ex02"
        make clean;
        cd ..
    else
        if [ "$#" -eq 1 ]; then
            for DIR in ${SUB_DIRS}; do
                cd ${DIR}
                make clean
                cd ..
            done
        fi
    fi
fi

# FULL-CLEAN
if [ "$1" == "fclean" ]; then
    if [ "$2" == "ex00" ] || [ "$2" == "ex00/" ]; then
        cd "ex00"
        make fclean;
        cd ..
    elif [ "$2" == "ex01" ] || [ "$2" == "ex01/" ]; then
        cd "ex01"
        make fclean;
        cd ..
    elif [ "$2" == "ex02" ] || [ "$2" == "ex02/" ]; then
        cd "ex02"
        make fclean;
        cd ..
    else
        if [ "$#" -eq 1 ]; then
            for DIR in ${SUB_DIRS}; do
                cd ${DIR}
                make fclean
                cd ..
            done
        fi
    fi
fi