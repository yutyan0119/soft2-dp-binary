# software2 week5-assignment

## helloworld
`calc_magicnumber`の説明を書いておきます。
`union`で、bit演算しやすくなるように、intとメモリを共有したfloat変数を用意し、主にint型をいじって最後にfloatとして値を出して、それをコピペして`helloworld1.c`に入れました。

float型はサイズ上、char型4つを並べたbitを収納出来るので、文字列から文字を取ってasciiコードをリトルエンディアンにそぐうようにシフトして、代入するということを繰り返しました。

## fibo
`mul_matrix`は、行列の掛け算をする関数です。`pow_matrix`は、行列の累乗を計算します。
$A^n$は$n$が2で割れるときには、$A^{\frac{n}{2}}$の2乗を返し、$n$が2で割り切れないときには、$A^{\frac{n-1}{2}}$に$A$をかけて返します。
`mul_matrix`は、同じ行列の掛け算（＝2乗）が出来るように、一旦結果を別の変数に入れてコピーして引数に代入し、返すようにしています。

## 0-1knapsack
`item.c`に`load_itemset`を書きました。`write_binary.c`では、`knapsack.dat`に`load_itemset`に適した形のバイナリファイルを出力するプログラムを書いてあります。

## tsp1
`tsp1.md`より抜粋

## advance
`advance.md`より抜粋
