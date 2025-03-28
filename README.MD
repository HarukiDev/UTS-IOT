# Integrasi Wokwi ke VSCode dan Penggunaan Blynk

## Deskripsi

Program ini digunakan untuk memantau suhu dan kelembapan menggunakan sensor DHT22 yang terhubung dengan ESP32. Data yang diperoleh akan dikirim ke platform Blynk untuk dipantau melalui dashboard.

## Blynk

### 1. Membuat Template
- Masuk ke **Developer Zone** di Blynk.
- Buat **Template Baru**.
- Masuk ke menu **Datastream** dan buat dua variabel:
  - `suhu` (double) pin v0 dengan unit celcius, min 0 max 100
  - `kelembapan` (integer) pin v1 dengan unit percentage, min 0 max 100

### 2. Mengatur Web Dashboard
- Tambahkan **Widget Gauge** pada **Web Dashboard**.
- Hubungkan widget dengan datastream yang telah dibuat sebelumnya.

### 3. Membuat Device Baru
- Buka menu **Device** > **Create New Device**.
- Pilih template yang sudah dibuat.
- Salin kode atau token yang muncul di sudut kanan atas (notifikasi).

---

## Instalasi Wokwi ke VSCode
1. **Install PlatformIO IDE**
   - Buka VSCode dan install ekstensi **PlatformIO IDE**.
   - Setelah instalasi, klik ikon **PlatformIO** di sudut kiri VSCode.
   - Tunggu hingga instalasi selesai. Jika sudah, akan muncul ikon **rumah** di sudut kiri bawah VSCode.
   - Klik ikon **rumah**, lalu pilih **Project Wizard**.
   - Isi **Project Wizard**:
     - Board: `esp32doit-devkit-v1`
     - Framework: `Arduino`
   - Buat proyek baru.

2. **Menambahkan Kode dan Library**
   - Buka folder proyek dan navigasi ke folder `src`.
   - Edit file `main.cpp` dengan kode yang akan dijalankan.
   - Untuk menambahkan library:
     - Buka **PlatformIO Home**
     - Pilih **Libraries** di sidebar kiri
     - Install library yang dibutuhkan.
   - Bangun proyek dengan **Build C++**.

3. **Instalasi Wokwi Simulator**
   - Install **Wokwi Simulator** melalui VSCode.
   - Jika muncul **license request** di sudut kanan bawah, ikuti instruksi yang diberikan.

4. **Konfigurasi Wokwi**
   - Buat file baru di luar `src`, beri nama `wokwi.toml`.
   - Isi `wokwi.toml` dengan konfigurasi berikut:
     ```toml
     [wokwi]
     version = 1
     firmware = '.pio\build\esp32doit-devkit-v1\firmware.bin'
     elf = '.pio\build\esp32doit-devkit-v1\firmware.elf'
     ```
   - Setelah proses build, akan muncul firmware di folder `.pio/build/esp32doit-devkit-v1/`. Salin path `firmware.bin` dan `firmware.elf`, lalu sesuaikan di `wokwi.toml`.

5. **Membuat Diagram Wokwi**
   - Buat file `diagram.json`.
   - Salin kode dari **Wokwi Simulator** ke dalam `diagram.json`.
   - Jika `diagram.json` sudah ada dan tidak bekerja, hapus file tersebut lalu buat ulang.

6. **Menjalankan Kode**
   - Tekan `Ctrl + Shift + P` lalu pilih **Start Wokwi Simulator**.
   - Jika semuanya sudah benar, simulator akan berjalan tanpa kendala.
