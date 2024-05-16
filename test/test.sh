./artifact/NAIL_cl.exe ./test/test.nil

exit 0
cc -o ./test/res ./test/out.s -static
./test/res
actual="$?"
echo "return : $actual"
rm ./test/res.exe