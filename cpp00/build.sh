SUBDIRS="ex00 ex01"

if [ "$1" == "" ]; then
    for DIR in $SUBDIRS; do
        cd $DIR
        make
        cd ..
        echo ""
    done
fi

if [ "$1" == "clean" ]; then
    for DIR in $SUBDIRS; do
        cd $DIR
        make clean
        cd ..
    done
fi


if [ "$1" == "fclean" ]; then
    for DIR in $SUBDIRS; do
        cd $DIR
        make fclean
        cd ..
    done
fi
