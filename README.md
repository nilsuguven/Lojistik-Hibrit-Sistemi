# Lojistik-Hibrit-Sistemi
Lojistik Hibrit Sistemi (Graf ve Hash Tablosu)
Bu proje, bir lojistik firmasının şehirler arası bağlantılarını yönetmek için Graf (Graph) yapısını, paket bilgilerini hızlı sorgulamak için ise Hash Tablosu (Hash Table) yapısını hibrit olarak kullanan bir sistemdir.

Kullanılan Teknikler
Bu proje, öğrenci numaramın (...69) son iki hanesine göre belirlenen şu teknikleri içermektedir:

Hash Fonksiyonu: Tip B (ASCII Toplamı Tabanlı)

Çakışma (Collision) Çözümü: Zincirleme (Chaining - Linked List)

Graf Gezinme: BFS (Sığ Öncelikli Arama)

Proje Yapısı
Proje, modüler bir yaklaşımla çoklu dosya yapısında geliştirilmiştir:

main.c: Ana menü ve sistem entegrasyonu.

hash_table.c / .h: Kargo takibi ve hash işlemleri.

graph.c / .h: Lojistik ağı ve BFS rotalaması.
