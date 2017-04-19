# ＡＥＳＴＨＥＴＩＣ
Make your words more ＡＥＳＴＨＥＴＩＣ

```
USAGE:
   ＡＥＳＴＨＥＴＩＣ [OPTION]...
   
OPTIONS:
   -f      INPUT FILENAME (uses STDIN if omitted)
   -h      HELP: THIS MESSAGE
   
NOTES:
   Runs in ＩＮＴＥＲＡＣＴＩＶＥ　ＭＯＤＥ when STDIN is the TTY.
   Press Ctrl+D to send an EOF character to exit.
```

## ＷＨＹ？
### FIGLET-STYLE HEADINGS

1. Put the following in your `.vimrc`, then save:<br/>
   `vnoremap <leader>a :!ＡＥＳＴＨＥＴＩＣ<CR>`
2. Reload vim config with `:source $MYVIMRC`.
3. Select text in visual mode, `<leader>a` will transform the selection.

### CODE PRANKS

```
／／　ＴＲＡＮＳＬＡＴＥ　ＴＯ　ＴＩＴＬＥ　ＣＡＰＳ
ｗｈｉｌｅ（　１　）　｛

   ｃｈｒ　＝　ｆｇｅｔｃ（ｐＦｉｌｅ）；

   ｉｆ（　ｃｈｒ　＝＝　ＥＯＦ　）
      ｂｒｅａｋ；

   ／／　ＡＳＣＩＩ　ＣＨＡＲＳ
   ｉｆ（　（ｃｈｒ　＞＝　０ｘ２１）　＆＆　（ｃｈｒ　＜＝　０ｘ７Ｅ）　）　｛

      ｆｐｕｔ＿ｕｔｆ８ｃｐ（（ｃｈｒ　－　０ｘ２１）　＋　０ｘｆｆ０１，　ｓｔｄｏｕｔ）；
   ｝
   ／／　ＳＰＡＣＥ
   ｅｌｓｅ　ｉｆ　（ｃｈｒ　＝＝　＇　＇）　｛

      ｆｐｕｔ＿ｕｔｆ８ｃｐ（０ｘ３０００，　ｓｔｄｏｕｔ）；
   ｝
   ／／　ＯＴＨＥＲ
   ｅｌｓｅ　｛

      ｆｐｕｔｃ（ｃｈｒ，　ｓｔｄｏｕｔ）；
   ｝
｝；
```

### ＡＥＳＴＨＥＴＩＣＳ AT YOUR FINGERTIPS
```
$ ./ＡＥＳＴＨＥＴＩＣ 
ＩＮＴＥＲＡＣＴＩＶＥ　ＭＯＤＥ (PRESS CTRL+D TO EXIT):

> figlet-y headings
ｆｉｇｌｅｔ－ｙ　ｈｅａｄｉｎｇｓ

> VAPORWAVE
ＶＡＰＯＲＷＡＶＥ

> why would you do that?
ｗｈｙ　ｗｏｕｌｄ　ｙｏｕ　ｄｏ　ｔｈａｔ？

> Testing, 1 2 3 4...
Ｔｅｓｔｉｎｇ，　１　２　３　４．．．
```

## ＤＩＲＥＣＴＩＯＮＳ
1. Install semi-recent versions of `gcc` and `make` for your OS.
2. Run `make`.
3. Put the path to the binary `ＡＥＳＴＨＥＴＩＣ` somewhere on your `$PATH`.
4. ｅｎｊｏｙ
