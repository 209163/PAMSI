# Lab2 - tablica dynamiczna

Kod czytelny, poprawnie sformatowany
Sposób pomiaru czasu nie jest właściwy.
``static_cast <double>(clock()) /CLOCKS_PER_SEC;``
Proszę korzystać z ``gettimeofday()`` http://linux.die.net/man/2/gettimeofday

# Lab3 - projektowanie obiektowe

Proszę nie zostawiać w kodzie bloków komentarzy - jeśli były zacommitowane,
to jest to wystarczające do odtworzenia tego kodu. Bloki komentarzy utrudniają czytanie.

Program poprawnie zaprojektowany obiektowo.

# Lab4 - ADT, lista / kolejka / stos

Proszę ponownie przeprowadzić obliczenia dotyczące wyszukiania w obrębie listy
oraz powtórnie wykonać wykresy. Na wykresie powinny znaleźc się:
- na osi OX rozmiar problemu
- na osi OY czas wykonania zadania
- poszczególne algorytmy lub rodzaj sprawdzanych zadań - osobne serie danych, róznymi kolorami.

Wykres ilustrujący czas przeszukiwania w zależności od miejsca, w którym znajduje się
wyszukiwany element dla np. listy zawierającej 10 elementów - nie ma sensu.


# Lab5 - sortowanie

# Lab6 - tablica asoc

Brak wyjaśnienia dlaczego złożoność zapisu jest O(n^2). Jest to szczególnie
dziwne dla tablicy o stałej liczbie slotów.
Badanie czasu odczytu przy pomocy tego samego słowa prowadzi do niepoprawnego
oszacowania złożoności. Słowo to mogło się znaleźć zawsze na pierwszej pozycji
jakiegoś slotu tablicy, więc taki pomiar jaki został przez Panią wykonany nie
daje żadnej informacji o średnim czasie odczytu.

Ocena: 3

# Lab7 - drzewa

Ocena: 3

# Lab8 - grafy (bfs,dfs)

Wnioski sprawozdania zawierają omówienie złożoności pamięciowej, dla nas bardziej
istotna jest złożoność czasowa. Informacje o wymogach pamięciowych implementacji(
z macierzą sąsiedztwa wzgledem takiej z listami jest istotna na etapie decyzji
którą z implementacji wybrać, ale nie to było przedmiotem analizy.
Brak więc omówienia złożoności implementacji BFS i DFS.

Ocena: 3

# Lab9 - grafy (b&b)

brak spraw.

Ocena: 2
