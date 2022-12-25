alias FILE='file1'

nos="$(echo STRING | sed -s 's/s//g')"

cd $FILE && cd $( echo -n $FILE | sed -s 's/$"file"//g')