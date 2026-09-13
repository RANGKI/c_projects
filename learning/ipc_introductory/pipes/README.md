# LEARN PIPENG ? PIPE NG ? PIPING ?

mencoba untuk membuat implementasi sederhana dari piping, contoh ketika kita melakukan perintah dengan simbol "|":

program1 | program2
echo "Hello Smoll" | base64

Thats is piping, this is what the project want to mimic the behaviour

## Explanation

Program ini memiliki 2 komponen penting, pipe() dan fork()

pipe() berguna untuk membuat 2 file descriptor yang memiliki fitur masing masing untuk read dan write, baca man 2 pipe atau jika lebih detail man 7 pipe

fork() berguna untuk mengsimulasikan perintah

pada dasarnya, saat kita membuka terminal kita sudah berada dalam sebuah process dan ketika kita meng enter sebuah command terminal akan melakukan fork()

jadi fork berguna untuk simulasi progam2

ketika melakukan fork, penting untuk membuat handler untuk mengenali mana program parent dan yang child. ketika fork mengembalikan 0 maka program tersebut adalah child dan jika yang dikembalikan angka besar maka program tersebut adalah main