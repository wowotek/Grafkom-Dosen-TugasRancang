# Grafkom-Dosen-TugasRancang

> Tugas Ini di rilis oleh  **Erlangga Ibrahim** secara terbuka (*Open Source*)
> Dibawah Lisensi **GNU GPLv3**. untuk keterangan dan informasi lebih lanjut mengenai
> Lisensi, dapat dibuka di : https://www.gnu.org/licenses/gpl-3.0.en.html
> atau dengan membaca file `LICENSE`
>  
> Semua sumber yang digunakan pada tugas ini, dapat dilihat pada :
> https://github.com/wowotek/Grafkom-Dosen-TugasRancang
>  
> **PERINGATAN** : *Tugas ini dirilis **setelah tenggat waktu** pengumpulan tugas, dan tidak akan berlaku untuk kolega dengan tenggat waktu pengumpulan yang sama*
>  
> **PERINGATAN** : *Tugas ini dirilis **tanpa garansi**, termasuk nilai yang di-nihilkan oleh sebab **mencontek** dan/atau **menyalin** dan/atau **meniru** yang bersumber dari tugas ini*

## Pengawas / Dosen

* **Pratyaksa Ocsa Saian** - *@pratyaksaocsa*

## Penulis

* **Aurelia Gabriele** (672017277) - *@aureliagbrl*
* **Erlangga Ibrahim** (672017282) - *@wowotek*

## Deskripsi Tugas

> NOTE : Belum ada ketentuan dari dosen terkait. harap update ini segera setelah mendapatkan ketentuan resmi dari dosen terkait
buat tugas susah pokoke

### Pembakuan

> NOTE : Belum ada ketentuan dari dosen terkait. harap update ini segera setelah mendapatkan ketentuan resmi dari dosen terkait

## Kontribusi

untuk melakukan kontribusi, ada beberapa hal yang perlu diketahui bebrapa diantaranya adalah :

### Panduan *Coding Style*

*Coding style* yang digunakan adalah gabungan dari **_GNU Coding Standards_** dan **_Object Pascal Style_** berikut penjabaran lebih lengkap mengenai kedua style tersebut :

* **GNU Coding Standards** : https://www.gnu.org/prep/standards/standards.html
* **Object Pascal / Delphi Style** : https://edn.embarcadero.com/article/10280

Secara singkat berikut contoh gabungan dari kedua standard tersebut:

```c++
#include <iostream>     // semua library standard harus ada diatas library-
#include <string.h>     // yang anda buat

#include "control.h"    // library anda harus ada setelah library standard

int exitCode = 0;       // nama variabel harus mengikuti gaya 'camelCase'

void RenderDisplay(void);   // definisi Fungsi mengikuti gaya standar C

void                    // tipe data implementasi fungsi harus ada diatas nama fungsi
RenderDisplay(void)     // nama fungsi dan definisi parameter harus mengikuti-
{                       // gaya Object-Pascal / Delphi
      ...
}

template <typename T> struct    // tipe data, dan definisi template mengikuti gaya-
vec2f_t {               // GNU Coding standard
    T x, y;
    ...  
}

int                     // mohon gunakan integer sebagai tipe data fungsi utama
main(int argc, char ** argv)
{
    ...

    return exitCode;
}

```

### *Forking* dan *Cloning* Repository

setelah memahami panduan Coding Style diatas, anda dapat mulai melakukan kontribusi dengan melakukan *Forking* lalu *Clone* dengan :

1. Forking
![Forking](.readme/fork.png)

2. Cloning
    ```bash
    git clone https://github.com/wowotek/Grafkom-Dosen-TugasRancang
    ```