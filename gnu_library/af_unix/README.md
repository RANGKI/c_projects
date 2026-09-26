# Belajar meng implementasikan socket unix

socket unix, berbeda dengan protocol tcp internet pada umum nya yang biasanya meng involve ip, pada protocol unix atau inter processorcommunication (IPC) adalah protocol local yang digunakan untuk aplikasi aplikasi yang tidak mengekspos dirinya ke luar internet

pro:
tentu saja cepat, karena hanya untuk implementasi local

cons:
hanya bisa komunikasi di dalam mesin ini saja

pengalaman ku menggunakan unix protocol (DGRAM/UDP Socket)

1. pastikan untuk selalu mengecek -1 untuk menghemat waktu debug -_- aku dapat error 98 (pada udp_server) dan 111 (udp_client)
2. ketika menggunakan unix socket, pastikan untuk unlink/rm file socket nya, karena jika tidak maka bind() akan error 98 (address already in use) karena file nya masih ada