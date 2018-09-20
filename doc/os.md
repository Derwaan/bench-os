# Operating Systems

## RIOT-OS

### Build with RIOT on Zolertia RE-MOTE

[Github repository](https://github.com/RIOT-OS/RIOT)

```bash
make BOARD=remote-reva
make BOARD=remote-reva flash
make BOARD=remote-reva term
```

## Contiki

> Deprecated

[Github repository](https://github.com/contiki-os/contiki)

### Build with Contiki on Zolertia RE-MOTE

```bash
make TARGET=zoul savetarget
make
sudo make example.upload
sudo make login
```
