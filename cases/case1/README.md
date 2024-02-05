### Introduction
The code for Case 1.

### Execute and Uninstall
First use `gcc` to compile **exception.c**, and move **a.out** under **/root/**.
Other instructions are similar to README.md in **strategies/upcalls_from_kernel**.

### Logs
```shell
[ 4127.789378] ret=136
[ 4127.789380] call_usermodehelper module isstarting..!
[ 4127.789760] traps: a.out[7636] trap divide error ip:55d6e41ac609 sp:7ffcec177170 error:0 in a.out[55d6e41ac000+1000]
[ 4127.989541] ret=136
[ 4127.989543] call_usermodehelper module isstarting..!
[ 4127.989950] traps: a.out[7638] trap divide error ip:55c45a809609 sp:7ffe1cfc5e70 error:0 in a.out[55c45a809000+1000]
[ 4128.174340] ret=136
[ 4128.174341] call_usermodehelper module isstarting..!
[ 4128.174742] traps: a.out[7640] trap divide error ip:559ea3943609 sp:7ffda6a19dc0 error:0 in a.out[559ea3943000+1000]
```