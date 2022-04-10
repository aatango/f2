# Output file
The results of a given calculatio
The detailed results are output to an ASCII file, which is split into the following sections:

* summary of calculation, and results;
* nodal results; and
* beam results.

 
## Summary of calculation, and results
_(Also included in the console printout)_

<!--
Quick checksum; max N, V, and M values; max reaction components. Always with their associated node, bar.
-->

```
CHECK			X [kN]	Y [kN]	M [kNm]
-----------------------------------------------
SUM OF REACTIONS	f.xxx	f.yyy	f.mmm
MAX REACTIONS		r.xxx	r.yyy	r.mmm

			N [kN]	V [kN]	M [kNm]
-----------------------------------------------
MAX INTERNAL FORCES	f.nnn	f.vvv	f.mmm
```



## Nodal results
```
NO	POSITION		DISPLACEMENT			REACTION
#	X [m]	Y [m]		X [m]	Y [m]	T [m]		X [kN]	Y [kN]	T [kN]	M [knM]
-----------------------------------------------------------------------------------------------
1	p.xxx	p.yyy		d.xxx	d.yyy	d.nnn		r.xxx	r.yyy	r.nnn	r.mmm
.
.
.
N
```

## Beam results
```
EL	NODES		LENGTH		CROSS SECTION			INTERNAL FORCES
#	START	END	[m]		A [m2]	E [GPa]	I [m4]		N [kN]	V [kN]	M [kNm]
-----------------------------------------------------------------------------------------------
1	n1	n2	L.lll		A.aaa	E.eee	I.iii		f.nnn	f.vvv	f.mmm
.
.
.
M
```
