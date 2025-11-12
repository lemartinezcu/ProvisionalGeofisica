# ReMi Pick Checker (estricto) – c = 0.91/p

Este pequeño tool genera un Excel (.xlsx) que valida automáticamente tus picks ReMi con criterios estrictos y tu convención c = 0.91/p. Solo pegas tus puntos (f, p) y marca en verde los válidos.

## Qué valida (en palabras sencillas)
- Geófonos y arreglo:
  - dx: separación entre geófonos.
  - N: número de geófonos.
  - L: largo útil del arreglo = (N−1)·dx.

- Tus puntos:
  - f (Hz): frecuencia.
  - p (s/m): lentitud (inversa de la velocidad).
  - c (m/s): velocidad de fase. Usamos c = α/p con α = 0.91.
  - λ (m): longitud de onda = c/f.

- Reglas estrictas para picar:
  1) No alias (muestreo espacial):
     - c ≥ c_min(f) = 2·f·dx
     - Equivalente en p: p ≤ p_alias(f) = α / (2·dx·f)
  2) Apertura del arreglo (ondas muy largas):
     - λ ≤ 0.5·L
     - En p: p ≥ α / (λ_max·f) con λ_max = 0.5·L
  3) Espaciamiento (ondas muy cortas):
     - λ ≥ 3·dx
     - En p: p ≤ α / (λ_min·f) con λ_min = 3·dx

  En conjunto, un punto es válido si:
  - max(2·f·dx, f·λ_min) ≤ c ≤ f·λ_max
  - (o, en p): α/(λ_max·f) ≤ p ≤ min[ α/(λ_min·f), α/(2·dx·f) ]

- Glosario rápido:
  - Pick: el punto que marcas sobre la “mancha” de energía para cada frecuencia.
  - Aliasiado: confusión de ondas por muestreo; ocurre cuando intentas ver detalles más pequeños que tu separación dx.
  - Modo fundamental (M0): la rama más lenta (velocidad menor) a una frecuencia dada; modos superiores (M1, M2...) son más rápidos.

## Cómo usar
1) Instala dependencias (solo una):
   - Python 3.8+ y `pip install openpyxl`
2) Coloca tus datos en `input_picks.csv` (o exporta desde max2curve y ajusta columnas).
3) Ejecuta:
   ```
   python tools/remi_checker/make_re_mi_checker_xlsx.py --dx 3.5 --n 24 --alpha 0.91 --input tools/remi_checker/input_picks.csv --output tools/remi_checker/remi_pick_checker_strict.xlsx
   ```
4) Abre `tools/remi_checker/remi_pick_checker_strict.xlsx`:
   - Hoja “Picks”: verás columnas calculadas y banderas:
     - alias_ok, lambda_ok, p_window_ok, overall_valid
   - Pega nuevos datos desde la fila 9 (A–D) y se recalcula.
   - Cambia dx y N en celdas B1 y B2 si tu arreglo cambia.

## Consejos prácticos
- Si ves dos manchas a la misma f, el fundamental es la más lenta (p más alto), siempre y cuando caiga dentro de la “ventana válida”.
- Para cubrir más bajas frecuencias (λ grandes), necesitas mayor L (más geófonos o mayor dx). Para asegurar altas frecuencias (λ pequeñas), necesitas dx más chico.
- No fuerces picks fuera de la ventana: suelen ser alias o lóbulos secundarios.

## Referencias
- Louie, J. N. (2001). “Faster, Better: Shear-wave velocity to 100 meters depth from refraction microtremor arrays (ReMi).” BSSA 91(2), 347–364.
- Park, C. B., Miller, R. D., Xia, J. (1999). “Multichannel analysis of surface waves.” Geophysics 64(3), 800–808.
- Documentación de Geopsy (arrays y f–k): https://www.geopsy.org
