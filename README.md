Victim
=======

## About it
Vimの操作っぽく作られたBrainf\**kの亜種です。実装はC++です。

## Syntax
基礎的な部分はBrainf\**kと同様です。以下、対応表です。

| Victim | Brainf\**k |
| --- | --- |
| h | < |
| l | > |
| k or \<C-a\> | + |
| j or \<C-x\> | - |
| f | [ |
| F | ] |
| p | . |
| i | , |

また、\" から行末まではコメントと見做されます。

## Install
`$ git clone http://github.com.KPCCoiL/Victim.git && cd Victim && make`

こんなもんでいちいちパス通しても迷惑だと思うので通しません。その場にインタプリタのバイナリが出来ます。

## Usage
`$ ./runvtm hoge.vtm`
