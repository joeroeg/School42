# !/bin/zsh

echo "running simple cases with 3 arguments"
ARG="1 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 1 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG

echo "running simple cases with 3 arguments"
ARG="1 2 3"; ./push_swap $ARG | wc -l
ARG="1 3 2"; ./push_swap $ARG | wc -l
ARG="2 1 3"; ./push_swap $ARG | wc -l
ARG="2 3 1"; ./push_swap $ARG | wc -l
ARG="3 1 2"; ./push_swap $ARG | wc -l
ARG="3 2 1"; ./push_swap $ARG | wc -l

echo "running simple cases with 4 arguments"
ARG="1 2 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 2 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 4 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 4 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 4 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 3 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 1 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 4 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 4 1 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 4 3 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 1 2 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 1 4 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 1 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 4 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 4 1 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 4 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 1 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 2 1 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 2 3 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 3 1 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG

ARG="1 2 4 3"; ./push_swap $ARG | wc -l
ARG="1 3 2 4"; ./push_swap $ARG | wc -l
ARG="1 3 4 2"; ./push_swap $ARG | wc -l
ARG="1 4 2 3"; ./push_swap $ARG | wc -l
ARG="1 4 3 2"; ./push_swap $ARG | wc -l
ARG="2 1 3 4"; ./push_swap $ARG | wc -l
ARG="2 1 4 3"; ./push_swap $ARG | wc -l
ARG="2 3 1 4"; ./push_swap $ARG | wc -l
ARG="2 3 4 1"; ./push_swap $ARG | wc -l
ARG="2 4 1 3"; ./push_swap $ARG | wc -l
ARG="2 4 3 1"; ./push_swap $ARG | wc -l
ARG="3 1 2 4"; ./push_swap $ARG | wc -l
ARG="3 1 4 2"; ./push_swap $ARG | wc -l
ARG="3 2 1 4"; ./push_swap $ARG | wc -l
ARG="3 2 4 1"; ./push_swap $ARG | wc -l
ARG="3 4 1 2"; ./push_swap $ARG | wc -l
ARG="3 4 2 1"; ./push_swap $ARG | wc -l
ARG="4 1 2 3"; ./push_swap $ARG | wc -l
ARG="4 1 3 2"; ./push_swap $ARG | wc -l
ARG="4 2 1 3"; ./push_swap $ARG | wc -l
ARG="4 2 3 1"; ./push_swap $ARG | wc -l
ARG="4 3 1 2"; ./push_swap $ARG | wc -l
ARG="4 3 2 1"; ./push_swap $ARG | wc -l

echo "running simple cases with 5 arguments"
ARG="1 2 3 4 5"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 3 5 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 4 3 5"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 4 5 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 5 3 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 5 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 2 4 5"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 2 5 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 4 2 5"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 4 5 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 5 2 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 5 4 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 4 2 3 5"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 4 2 5 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 4 3 2 5"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 4 3 5 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 4 5 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 4 5 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 5 2 3 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 5 3 2 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 5 3 4 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 5 4 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 5 4 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 3 4 5"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 3 5 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 4 3 5"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 4 5 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 5 3 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 5 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 1 4 5"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 1 5 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 4 1 5"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 4 5 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 5 1 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 5 4 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 4 1 3 5"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 4 1 5 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 4 3 1 5"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 4 3 5 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 1 5 4"; ./push_swap $ARG | wc -l
ARG="2 3 5 1 4"; ./push_swap $ARG | wc -l
ARG="2 5 1 4 3"; ./push_swap $ARG | wc -l
ARG="3 1 5 4 2"; ./push_swap $ARG | wc -l
ARG="3 2 5 1 4"; ./push_swap $ARG | wc -l
ARG="4 2 3 1 5"; ./push_swap $ARG | wc -l







echo "running mandatory cases"

ARG="1 2 3 4 5"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 3 4 5 6 7 8 9 10"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="5 4 3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="5 4 3 2 1 -2147483648"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="5 4 3 2 1 2147483647"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="5 4 3 2 1 """; ./push_swap $ARG | ./checker_Mac $ARG
ARG="5 4 3 2 1 -0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="5 4 3 2 1 +0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 75 17 47 50 4 33 97 41 82 59 99 87 42 77 78 36 49 86 68 84 94 63 55 71 31 6 54 74 76 89 100 65 30 18 46 22 96 13 28 73 24 8 79 34 56 57 16 95 40 62 1 60 85 69 14 37 19 20 15 25 66 91 44 26 81 90 9 58 83 7 2 38 27 39 51 61 45 10 23 48 80 72 64 98 93 43 29 12 5 67 92 88 21 53 52 32 35 70 11"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="92 45 430 158 140 161 321 356 402 234 416 399 320 336 241 436 276 54 393 80 441 272 237 217 198 159 185 110 170 398 284 144 339 358 143 482 485 243 245 264 55 153 461 314 439 128 452 9 147 413 451 419 288 494 469 28 334 460 258 100 274 384 115 35 124 423 467 322 421 14 73 444 79 2 479 171 172 354 5 417 82 72 70 223 499 331 459 127 65 364 372 404 435 450 200 396 295 278 191 368 146 81 394 409 67 3 406 29 411 233 456 229 150 388 154 187 500 20 454 466 194 97 139 135 407 250 252 57 347 315 210 446 60 34 182 383 429 280 492 141 176 152 43 493 498 293 275 195 51 478 113 420 173 30 465 434 181 403 77 395 96 437 214 369 230 386 16 282 1 188 391 41 309 157 462 63 410 349 376 98 332 401 463 490 307 418 357 325 424 239 220 86 488 397 464 259 169 254 318 201 380 66 361 313 270 11 473 215 489 211 17 414 405 497 346 265 400 25 408 341 175 381 348 308 89 277 480 422 292 39 472 7 481 375 95 42 487 49 283 136 8 256 443 213 21 33 101 253 64 219 4 112 496 111 122 199 184 353 31 221 304 392 475 371 387 306 390 83 240 226 178 342 105 326 333 204 19 269 431 149 58 343 212 91 145 286 130 190 160 440 377 114 260 27 13 227 32 228 129 301 162 208 428 126 235 94 216 207 483 427 378 186 132 179 385 316 468 267 495 285 289 317 196 415 329 155 151 163 327 192 109 263 330 249 261 193 302 142 445 382 36 389 23 242 10 53 78 121 433 69 62 374 85 40 203 137 138 425 471 102 379 442 291 106 116 273 359 246 299 447 300 56 75 44 236 148 180 344 366 412 448 87 232 373 38 477 345 24 167 312 224 90 108 365 123 118 244 156 484 133 247 262 458 328 71 26 298 47 189 340 297 352 48 367 449 107 362 296 337 88 165 209 168 311 426 474 360 134 319 59 438 231 294 74 257 202 177 305 99 303 290 279 131 18 117 37 166 103 491 255 486 46 287 470 266 457 164 271 93 22 453 206 174 183 323 52 15 68 268 370 205 120 432 248 238 281 197 310 363 351 350 119 12 455 84 125 104 61 225 50 222 218 335 76 355 6 476 251 324 338"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 3 4 5 6 7 8 9 10"

echo "running memory leak tests"

ARG="5 4 3 2 1"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./push_swap $ARG 2>&1 | grep -E 'definitely lost|indirectly lost|possibly lost|still reachable' | awk '$4 != "0" { print }'
ARG="4 3 2 1"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./push_swap $ARG 2>&1 | grep -E 'definitely lost|indirectly lost|possibly lost|still reachable' | awk '$4 != "0" { print }'
ARG="3 2 1"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./push_swap $ARG 2>&1 | grep -E 'definitely lost|indirectly lost|possibly lost|still reachable' | awk '$4 != "0" { print }'
ARG="3 2"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./push_swap $ARG 2>&1 | grep -E 'definitely lost|indirectly lost|possibly lost|still reachable' | awk '$4 != "0" { print }'
ARG="3"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./push_swap $ARG 2>&1 | grep -E 'definitely lost|indirectly lost|possibly lost|still reachable' | awk '$4 != "0" { print }'
ARG="5 4 3 2 1 -2147483648"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./push_swap $ARG 2>&1 | grep -E 'definitely lost|indirectly lost|possibly lost|still reachable' | awk '$4 != "0" { print }'
ARG="5 4 3 2 1 2147483647"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./push_swap $ARG 2>&1 | grep -E 'definitely lost|indirectly lost|possibly lost|still reachable' | awk '$4 != "0" { print }'
ARG="5 4 3 2 1 """
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./push_swap $ARG 2>&1 | grep -E 'definitely lost|indirectly lost|possibly lost|still reachable' | awk '$4 != "0" { print }'
ARG="5 4 3 2 1 -0"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./push_swap $ARG 2>&1 | grep -E 'definitely lost|indirectly lost|possibly lost|still reachable' | awk '$4 != "0" { print }'
ARG="5 4 3 2 1 +0"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./push_swap $ARG 2>&1 | grep -E 'definitely lost|indirectly lost|possibly lost|still reachable' | awk '$4 != "0" { print }'
ARG="3 75 17 47 50 4 33 97 41 82 59 99 87 42 77 78 36 49 86 68 84 94 63 55 71 31 6 54 74 76 89 100 65 30 18 46 22 96 13 28 73 24 8 79 34 56 57 16 95 40 62 1 60 85 69 14 37 19 20 15 25 66 91 44 26 81 90 9 58 83 7 2 38 27 39 51 61
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./push_swap $ARG 2>&1 | grep -E 'definitely lost|indirectly lost|possibly lost|still reachable' | awk '$4 != "0" { print }'45 10 23 48 80 72 64 98 93 43 29 12 5 67 92 88 21 53 52 32 35 70 11"
ARG="92 45 430 158 140 161 321 356 402 234 416 399 320 336 241 436 276 54 393 80 441 272 237 217 198 159 185 110 170 398 284 144 339 358 143 482 485 243 245 264 55 153 461 314 439 128 452 9 147 413 451 419 288 494 469 28 334 460 258 100 274 384 115 35 124 423 467 322 421 14 73 444 79 2 479 171 172 354 5 417 82 72 70 223 499 331 459 127 65 364 372 404 435 450 200 396 295 278 191 368 146 81 394 409 67 3 406 29 411 233 456 229 150 388 154 187 500 20 454 466 194 97 139 135 407 250 252 57 347 315 210 446 60 34 182 383 429 280 492 141 176 152 43 493 498 293 275 195 51 478 113 420 173 30 465 434 181 403 77 395 96 437 214 369 230 386 16 282 1 188 391 41 309 157 462 63 410 349 376 98 332 401 463 490 307 418 357 325 424 239 220 86 488 397 464 259 169 254 318 201 380 66 361 313 270 11 473 215 489 211 17 414 405 497 346 265 400 25 408 341 175 381 348 308 89 277 480 422 292 39 472 7 481 375 95 42 487 49 283 136 8 256 443 213 21 33 101 253 64 219 4 112 496 111 122 199 184 353 31 221 304 392 475 371 387 306 390 83 240 226 178 342 105 326 333 204 19 269 431 149 58 343 212 91 145 286 130 190 160 440 377 114 260 27 13 227 32 228 129 301 162 208 428 126 235 94 216 207 483 427 378 186 132 179 385 316 468 267 495 285 289 317 196 415 329 155 151 163 327 192 109 263 330 249 261 193 302 142 445 382 36 389 23 242 10 53 78 121 433 69 62 374 85 40 203 137 138 425 471 102 379 442 291 106 116 273 359 246 299 447 300 56 75 44 236 148 180 344 366 412 448 87 232 373 38 477 345 24 167 312 224 90 108 365 123 118 244 156 484 133 247 262 458 328 71 26 298 47 189 340 297 352 48 367 449 107 362 296 337 88 165 209 168 311 426 474 360 134 319 59 438 231 294 74 257 202 177 305 99 303 290 279 131 18 117 37 166 103 491 255 486 46 287 470 266 457 164 271 93 22 453 206 174 183 323 52 15 68 268 370 205 120 432 248 238 281 197 310 363 351 350 119 12 455 84 125 104 61 225 50 222 218 335 76 355 6 476 251 324 338"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./push_swap $ARG 2>&1 | grep -E 'definitely lost|indirectly lost|possibly lost|still reachable' | awk '$4 != "0" { print }'
ARG="1 2 3 4 5 6 7 8 9 10"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./push_swap $ARG 2>&1 | grep -E 'definitely lost|indirectly lost|possibly lost|still reachable' | awk '$4 != "0" { print }'

echo "running test of error cases "

ARG="5 4 3 2 1 1"
./push_swap $ARG | ./checker_Mac $ARG
ARG="5 4 3 2 1 0a"
./push_swap $ARG | ./checker_Mac $ARG
ARG="5 4 3 2 1 -2147483649"
./push_swap $ARG | ./checker_Mac $ARG
ARG="5 4 3 2 1 2147483648"
./push_swap $ARG | ./checker_Mac $ARG
ARG="5 4 3 2 1 -"
./push_swap $ARG | ./checker_Mac $ARG
ARG="5 4 3 2 1 +"
./push_swap $ARG | ./checker_Mac $ARG
ARG="5 4 3 2 1 - 1"
./push_swap $ARG | ./checker_Mac $ARG
