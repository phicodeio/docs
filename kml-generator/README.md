# KML GENERATOR 

Generate DJI KML Files from COORDINATE arrays.

## WORKING
INPUT FORMAT : Array of arrays containing all the paths P1,P2,P3,P4 and Reference: In That Order. 
```python
t1 = [
    [10.897300445758209,77.26449520833499,58.132146668974190],
    [10.897300445758209,77.26449520833499,58.132146668974190],
    [10.897300445758209,77.26449520833499,58.132146668974190],
    ...
]
```


## FEATURES 
- Calculates Lookat 
- Has functionality for additional Actions 
- Fully modular 

## INSTRUCTIONS 
1. Install -> Activate the conda environment as provided. 
2. Run the jupyter notebook. 
3. Input the `t1` array. 
4. Input the path parameters.
4. `Shift` + `Enter` all the way to generate the KML File on the last cell. 

## CODES 
- __3point__ : 3 points in one path only. 
- __nPoint__ : Any number of points in one path. 