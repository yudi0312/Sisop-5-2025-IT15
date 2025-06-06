# Sisop-5-2025-IT15

## Kelompok

Nama | NRP
--- | ---
Putu Yudi Nandanjaya Wiraguna	| 5027241080
Naruna Vicranthyo Putra Gangga | 5027241105
Az Zahrra Tasya Adelia | 5027241087

## Daftar Isi

- [Kelompok](#kelompok)
- [Daftar Isi](#daftar-isi)
- [Soal](#soal)
- [Petunjuk Soal](#petunjuk-soal)
  - [Source](#source)
  - [Headers](#headers)
  - [Makefile](#makefile)
  - [Video Demonstrasi](#video-demonstrasi)
- [Laporan](#laporan)

## Soal

Pada suatu hari, anda merasa sangat lelah dari segala macam praktikum yang sudah ada, sehingga anda berencana untuk tidur yang nyenyak di sebuah jam 3:34AM yang cerah. Tetapi, anda terbangun di dalam dunia berbeda yang bernama "Eorzea". Ada sesuatu yang mengganggu pikiran anda sehingga anda diharuskan membuat sebuah operating system bernama "EorzeOS" untuk mendampingi diri anda dalam dunia ini.

1. Sebagai seorang main character dari dunia ini, ternyata anda memiliki kekuatan yang bernama "The Echo", kekuatan ini memungkinkan anda untuk berbicara pada Operating System ini (mungkin sebenarnya bukan ini kekuatannya, tetapi ini cukup kuat juga), dengan tujuan agar semua hal yang anda katakan, bila bukan merupakan sebuah command yang valid, akan mengulang hal yang anda katakan.

   Ilustrasi:
   ```
   user> Hello!
   Hello!
   user> I have the Echo
   I have the Echo
   ```

2. gurt: yo

   Ilustrasi:
   ```
   user> yo
   gurt
   user> gurt
   yo
   ```

3. Seorang main character memerlukan sebuah nama yang semua orang bisa ingat dengan baik. Buatlah sebuah command yang memungkinkan pengguna untuk mengubah nama user pada shell yang digunakan:
   * `user <username>` = mengubah username menjadi `<username>`
   * `user` = mengubah username menjadi default `user`
   
   Ilustrasi:
   ```
   user> user Tia
   Username changed to Tia
   Tia> user
   Username changed to user
   user>
   ```

4. Tiga negara besar dari Eorzean Alliance butuh bantuan anda untuk ikut serta dalam "Grand Company" mereka sehingga anda bisa mengubah warna terminal ajaib anda sesuai warna utama dari company mereka:
   * `grandcompany maelstrom` = clear terminal, ubah semua teks berikutnya jadi merah
   * `grandcompany twinadder` = clear terminal, ubah semua teks berikutnya jadi kuning
   * `grandcompany immortalflames` = clear terminal, ubah semua teks berikutnya jadi biru
   * `grandcompany <selain atau kosong>` = tunjukkan error message
   * `clear` = clear terminal, ubah semua teks berikutnya kembali jadi awal (para Grand Company sedih kamu netral)

   Selain mengubah seluruh warna terminal, nama anda di dalam terminal akan diberikan tambahan nama judul Grand Company:
   * Maelstrom = `user@Storm`
   * Twin Adder = `user@Serpent`
   * Immortal Flames = `user@Flame`
   * `clear` = menghapus nama grand company

   Ilustrasi:
   ```
   gurt> grandcompany maelstrom
   -- terminal clear menjadi warna merah --
   gurt@Storm> clear
   -- terminal clear menjadi warna putih --
   ```

5. Sebagai pahlawan terkenal di antara ketiga negara besar Eorzean Alliance, salah satu supplier senjata terbesar di seluruh Eorzea bernama "Rowena's House of Splendors" tiba-tiba memerlukan bantuan anda untuk membuat sebuah sistem kalkulator sederhana melalui command karena pemimpin mereka tertidur setelah mengurus semua orang di dalam Eorzea:
   * `add <x> <y>` = x + y
   * `sub <x> <y>` = x - y
   * `mul <x> <y>` = x * y
   * `div <x> <y>` = x / y

   Ilustrasi:
   ```
   user> add 4 2
   6
   user> sub 4 2
   2
   user> mul 3 -2
   -6
   user> div -6 -2
   3
   ```

6. me: yogurt
   
   gurt:
   * `yo`
   * `ts unami gng </3`
   * `sygau`

   pilih secara *random*

   Ilustrasi:
   ```
   user> yogurt
   gurt> yo
   user> yogurt
   gurt> ts unami gng </3
   user> yogurt
   gurt> sygau
   ```

8. Perusahaan mesin "Garlond Ironworks" tiba-tiba lelah mengurus permintaan senjata perang untuk orang ke-148649813234 yang berusaha menghadapi final boss yang sama, sehingga mereka perlu bantuan kamu untuk melengkapi `Makefile` yang diberikan dengan command-command yang sesuai untuk compile seluruh operating system ini.

## Petunjuk Soal

### Source

* [kernel.asm](src/kernel.asm)
  * `_putInMemory`: penjelasan terdapat dalam modul
  * `_interrupt`: fungsi untuk interrupt
    * `number`: interrupt vector number
    * `AX`,`BX`,`CX`,`DX`: register untuk diisi
    * `AX` merupakan kombinasi dari `AH` dan `AL`, pola ini juga berlaku untuk `BX`,`CX`, dan `DX`
    * Untuk menggabungkan jenis register `H` dan `L` menjadi `X` bisa menggunakan salah satu metode berikut:
      ```c
      AX = AH << 8 | AL    // first method
      AX = AH * 256 + AL   // second method
      ```
   * `getBiosTick`: fungsi untuk mendapatkan tick dari BIOS
* [kernel.c](src/kernel.c)
  * Diisi penerapan fungsi `printString`, `readString`, dan `clearScreen` dengan bantuan `kernel.asm`
    * untuk `printString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` dengan parameter `AH = 0x0E` untuk _teletype output_. Karakter yang ditampilkan dapat dimasukkan pada register `AL`. Fungsi ini akan menampilkan string karakter ASCII (_null-terminated_) ke layar.
    * untuk `readString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 16h` dengan parameter `AH = 0x00` untuk _keyboard input_. Fungsi ini akan membaca karakter ASCII (_non-control_) yang dimasukkan oleh pengguna dan menyimpannya pada buffer hingga menekan tombol `Enter`. Handle tombol `Backspace` dibebaskan kepada praktikan.
    * untuk `clearScreen`: Ukuran layar adalah `80x25` karakter. Setelah layar dibersihkan, kursor akan kembali ke posisi awal yaitu `(0, 0)` dan buffer video untuk warna karakter diubah ke warna putih. Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` atau menggunakan fungsi `putInMemory` untuk mengisi memori video.
* [shell.c](src/shell.c)
  * Diisi penerapan shell yang menggunakan fungsi kernel untuk parsing keseluruhan command yang diinput

### Headers

* [std_type.h](include/std_type.h)
  * `byte`: unsigned char data type, untuk angka 0-255 (`0x00`-`0xFF`)
  * `bool`: untuk boolean (true/false), karena boolean tidak built-in
* [std_lib.h](include/std_lib.h)
  * `div`: division
  * `mod`: modulo
  * Pembagian dan modulo tidak ada dalam assembly, sehingga harus dilengkapi dengan operator yang tersedia (`+`,`-`,`*`,`<<`,`>>`)
  * `strcmp`: membandingkan dua string
  * `strcpy`: copy string
  * `clear`: fill memory dengan `0`
  * `atoi`: alphanumeric to integer (string menjadi angka)
  * `itoa`: integer to alphanumeric (angka menjadi string)
* [kernel.h](include/kernel.h)
  * Deklarasi header untuk fungsi-fungsi dalam `kernel.c`
* [shell.h](include/shell.h)
  * Deklarasi header untuk fungsi-fungsi dalam `shell.c`

### Makefile

* [makefile](./makefile)
   * `prepare` : membuat disk image baru `floppy.img` pada direktori `bin/` dengan ukuran 1.44 MB.
   * `bootloader` : mengkompilasi `bootloader.asm` menjadi `bootloader.bin` pada direktori `bin/`.
   * `stdlib` : mengkompilasi `std_lib.c` menjadi `std_lib.o` pada direktori `bin/`.
   * `shell`: mengkompilasi `shell.c` menjadi `shell.o` pada direktori `bin/`.
   * `kernel` : mengkompilasi `kernel.c` menjadi `kernel.o` pada direktori `bin/` dan mengkompilasi `kernel.asm` menjadi `kernel_asm.o` pada direktori `bin/`.
   * `link` : menggabungkan `bootloader.bin`, `kernel.o`, `kernel_asm.o`, dan `std_lib.o` menjadi `floppy.img`.
   * `build` : menjalankan perintah `prepare`, `bootloader`, `stdlib`, `kernel`, dan `link`.

### Video Demonstrasi

[Akses Video dalam Assets](./assets/demo.mkv)

https://github.com/user-attachments/assets/c8b10c0b-475a-4ae6-8714-a9ca529d5d42



## Laporan

# Laporan Pengerjaan EorzeOS

EorzeOS adalah sebuah sistem operasi sederhana berbasis shell interaktif yang dibangun sebagai respons dari skenario fiksi pada dunia "Eorzea". Sistem ini mencakup fitur percakapan (echo), pengubahan identitas pengguna, terminal tematik berdasarkan Grand Company, kalkulator, dan build system.

---

## 1. The Echo

Shell akan membalas input yang tidak dikenali sebagai command valid dengan mengulangnya kembali.

**Contoh:**

```
user> Hello!
Hello!
```

**Implementasi:**

* Di `shell.c`, command yang tidak cocok dengan keyword manapun akan dicetak ulang menggunakan `printString`.

---

## 2. Fitur gurt: yo

Shell memiliki fitur khusus di mana:

* Input `yo` akan merespon `gurt`.
* Input `gurt` akan merespon `yo`.

**Contoh:**

```
user> yo
gurt
user> gurt
yo
```

**Implementasi:**

* Cek string input. Jika `yo`, output `gurt`; jika `gurt`, output `yo`.

---

## 3. Ubah Nama User

Command `user` digunakan untuk mengganti username shell.

* `user <nama>` → mengubah username.
* `user` → reset ke `user`.

**Contoh:**

```
user> user Tia
Username changed to Tia
Tia> user
Username changed to user
```

**Implementasi:**

* Menyimpan nama username dalam variabel.
* Mengubah prompt shell berdasarkan nama tersebut.

---

## 4. Grand Company (Warna Terminal & Prompt)

Mengubah warna terminal dan prompt berdasarkan perintah:

* `grandcompany maelstrom` → merah, prompt `@Storm`
* `grandcompany twinadder` → kuning, prompt `@Serpent`
* `grandcompany immortalflames` → biru, prompt `@Flame`
* `grandcompany` tanpa argumen atau tidak valid → error
* `clear` → kembalikan ke netral (putih, tanpa Grand Company)

**Contoh:**

```
gurt> grandcompany maelstrom
-- terminal merah --
gurt@Storm> clear
-- terminal netral --
```

**Implementasi:**

* Mengatur warna karakter dengan interrupt `10h` atau `putInMemory`.
* Clear layar dengan `clearScreen`.
* Prompt ditambahkan sesuai status Grand Company.

---

## 5. Kalkulator Sederhana

Shell dapat melakukan operasi matematika sederhana:

* `add <x> <y>` → hasil x + y
* `sub <x> <y>` → hasil x - y
* `mul <x> <y>` → hasil x \* y
* `div <x> <y>` → hasil x / y

**Contoh:**

```
user> add 4 2
6
user> mul 3 -2
-6
```

**Implementasi:**

* Menggunakan `atoi` untuk konversi string ke integer.
* Melakukan operasi matematika.
* Output dikembalikan ke string dengan `itoa`.

---

## 6. Random Respon dari "yogurt"

Command `yogurt` menghasilkan respon acak dari:

* `yo`
* `ts unami gng </3`
* `sygau`

**Contoh:**

```
user> yogurt
gurt> ts unami gng </3
```

**Implementasi:**

* Mengambil BIOS tick dengan `getBiosTick`.
* Menggunakan hasil tick sebagai pseudo-random index dari list respon.

---

## 7. Makefile Build System

Makefile disiapkan untuk membantu membangun sistem operasi ini dengan target:

* `prepare` → membuat `floppy.img`
* `bootloader` → compile `bootloader.asm`
* `stdlib` → compile `std_lib.c`
* `shell` → compile `shell.c`
* `kernel` → compile `kernel.c` dan `kernel.asm`
* `link` → menggabungkan seluruh binary menjadi `floppy.img`
* `build` → menjalankan semua langkah di atas

**Implementasi:**

* Memanfaatkan `as`, `gcc`, dan `ld`.
* Semua output berada di direktori `bin/`.

**Cara Menjalankan di Terminal:**

* Buat image dari awal:
```
make build
```
> Output: bin/floppy.img yang siap dijalankan di emulator.
*perintah ini sekaligus menghapus perintah build sebelumnya + membuat image dari awal.

output:

![image](https://github.com/user-attachments/assets/6a23ba97-7410-49e7-acb4-16109693e7df)


---

## Struktur Proyek

```
.
├── include/
│   ├── std_type.h
│   ├── std_lib.h
│   ├── kernel.h
│   └── shell.h
├── src/
│   ├── kernel.asm
│   ├── kernel.c
│   └── shell.c
├── bin/
│   └── (output files)
├── makefile
└── readme.md
```

---

## Catatan

* Backspace dalam `readString` diimplementasikan untuk menghapus karakter input.
* Warna teks diubah secara global agar semua teks setelahnya mengikuti warna Grand Company.

