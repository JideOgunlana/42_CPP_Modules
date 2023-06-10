SUB_DIRS="ex00 ex01 ex02 ex03"
EX00_EXEC="ex00"
EX01_EXEC="ex01"
EX02_EXEC="ex02"
EX03_EXEC="ex03"
EXECUTABLES=("${EX00_EXEC}" "${EX01_EXEC}" "${EX02_EXEC}" "${EX03_EXEC}")
DIRECTORIES=("ex00" "ex01" "ex02" "ex03")


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
        if find "${EXECUTABLES[i]}" >/dev/null 2>&1; then
            printf "⚠️ Executable ${EXECUTABLES[i]} already exists. Skipping make\n\n"
        else
            make
        fi
        ./"${EXECUTABLES[i]}"
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
    elif [ "$2" == "ex03" ] || [ "$2" == "ex03/" ]; then
        cd "ex03"
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
    elif [ "$2" == "ex03" ] || [ "$2" == "ex03/" ]; then
        cd "ex03"
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
