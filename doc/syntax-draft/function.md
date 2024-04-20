# 関数
関数は
```
func 関数名(型 引数, ...) : 戻り値の型 {
    // Code here...
}
```
の形式で定義する。
## 引数の値
明示的に参照を示さない限り、値はコピーされる。

型の所には[型名](./type)を書く。
配列の場合は記法がいくつか
```
// 要素が3つのint32配列のみ受け付ける
func function1(int32[3] position) : bool {}

// 要素数任意のint32配列を受け付ける
func function1(int32[] position) : bool {}
```

## 引数によるオーバーロード
引数の型が違う関数は本質的には別の関数と見なす。呼び出す関数は呼び出し時の型に応じる
```
func f(int64 a) : void {
    std::print("a");
}
func f(string a) : void {
    std::print("b");
}
func run() {
    f(42); // print a
    f("42"); // print b
}
```

## 型の省略
**同一ファイル内で定義・使用する関数に限り**、任意の型を省略できる。
```
func samefile_func(var a, ...) {
    // code...
}
```
コンパイル時に与えられた値の型から戻り値も含めて自動的に推論、定義される。  
当然定義されていない関数や演算子が見つかった場合コンパイルエラーになる
```
func mlu_and_add(var a, var b) {
    return a * b + a;
}

func use(int64 i_64, int32 i_32) {
    mlu_and_add(i_64, i_64);  // mlu_and_add(int64 a, int64 b) : int64
    mlu_and_add(i_32, i_32);  // mlu_and_add(int32 a, int32 b) : int32
    mlu_and_add("foo", "bar" );  // operator string * string is not defined
}
```
## 呼び出す関数の優先順位
型が完全に一致した関数→型を変換すれば呼べる関数→引数の型指定のない関数
