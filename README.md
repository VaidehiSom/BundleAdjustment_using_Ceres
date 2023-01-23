# BUNDLE ADJUSTMENT USING CERES

## Running the code
### Build the file using
```
cd ~/ws
mkdir build
cd build
cmake ..
make
```
### Then to run on BAL the dataset given in problem-16-22106-pre.txt

```
cd ~/ws
./build/bundle_adjustment_ceres problem-16-22106-pre.txt
```


## Results

### Output will be like-

```
Header: 16 22106 83718normalized
bal problem file loaded...
bal problem have 16 cameras and 22106 points. 
Forming 83718 observations. 
Solving ceres BA ... 
iter      cost      cost_change  |gradient|   |step|    tr_ratio  tr_radius  ls_iter  iter_time  total_time
   0  1.842900e+07    0.00e+00    2.04e+06   0.00e+00   0.00e+00  1.00e+04        0    7.36e-02    2.43e-01
   1  1.449093e+06    1.70e+07    1.75e+06   2.16e+03   1.84e+00  3.00e+04        1    1.51e-01    3.94e-01
   2  5.848543e+04    1.39e+06    1.30e+06   1.55e+03   1.87e+00  9.00e+04        1    1.42e-01    5.37e-01
   3  1.581483e+04    4.27e+04    4.98e+05   4.98e+02   1.29e+00  2.70e+05        1    1.37e-01    6.74e-01
```

### Visualizing the point clouds from initial.ply and final.ply file-
