convert_temperatures(Fahr) :-
    Fahr =< 300,
    Celsius is (5.0 / 9.0) * (Fahr - 32),
    format('°F: ~d  °C: ~2f~n', [Fahr, Celsius]),
    NextFahr is Fahr + 20,
    convert_temperatures(NextFahr).
convert_temperatures(_).
