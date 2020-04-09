# Printf
 - Write a library that contains ft_printf, a funciton that will mimic the real printf

----
This function manages some conversions: `c s p d i u x X % n l ll h hh`. 

It is also manages combination of the following flags: `-0.*# +`.

If input has not valid format in real `printf`, `ft_printf` will do undefined behavior(*like print nothing*).

 - Leak check : ✅
 - Norm check : ❌
 - Tested by [pft_2019](https://github.com/cclaude42/PFT_2019) ✅
