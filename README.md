# 42 libasm

## 概要

アセンブリ言語でCの関数を再実装
- メモリ、スタック、レジスタを使って操作
- システムコールを呼ぶ
- スタックフレームを用いてローカル変数を管理
- メモリアライメントを意識

## Sample script

```zsh
git clone https://github.com/Masaya-Kamei/libasm.git
cd libasm
make
gcc -w main/main.c -I./includes -L. -lasm 
echo -e "\n---Output---"
./a.out
```

## キーワード

`アセンブリ言語`,`メモリ`,`レジスタ`,`スタック`,`スタックフレーム`,`メモリアライメント`,`セクション`,`システムコール`,`x86-64`,`呼出規約`
