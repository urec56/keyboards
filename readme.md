# My layouts

For using this repo you need to clone it to the `vial_qmk` directory. I tested it on the `159c0888457e5675c6dc0a881e7c5bd8b54203e7` commit of [vial](https://github.com/vial-kb/vial-qmk/commit/159c0888457e5675c6dc0a881e7c5bd8b54203e7).

For now it has firmwares for:
- [tbkmini](./bastardkb/tbkmini/readme.md)


## Requirements

For compiling the firmware and setting it on your keyboard you need to download the `make` and `qmk` utils. 

If you are using the `NixOS` distro then just run this command in the root of the `vial` directory
```sh
nix-shell shell.nix --run zsh
```
