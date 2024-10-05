#include "DHT.h"

// Definisikan tipe sensor yang digunakan (DHT11 atau DHT22)
#define DHTTYPE DHT22

// Pin data DHT yang terhubung ke Arduino
#define DHTPIN 2

// Inisialisasi DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Memulai komunikasi serial
  Serial.begin(9600);
  Serial.println("DHT22 sensor test!");

  // Memulai sensor DHT
  dht.begin();
}

void loop() {
  // Membaca suhu dan kelembaban
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Periksa apakah pembacaan gagal dan keluarkan pesan kesalahan
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Cetak hasil pembacaan ke Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");

  // Tunggu satu menit sebelum pembacaan sensor berikutnya
  delay(60000);
}