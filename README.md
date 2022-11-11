# ROS-SF

A Transparent and Efficient ROS Middleware using Serialization-Free Message

Presented in Middleware 2022 (https://middleware-conf.github.io/2022/)

The presentation video can be found at (https://www.youtube.com/watch?v=YQnJ4XYrbcE)

This work consists of three components: SFM Generator (under `./sfm_gen`), ROS-SF Library (under `./sfm_lib`) and ROS-SF Converter (under `./sfm_conv`).  We provide the source code of all of them in this repository, and we also provide a test workspace for latency test (under `./test_ws`). 

See the README.md in each folder for further information.

If you are interested, please cite our Middleware 2022 paper:

```
@inproceedings{DBLP:conf/middleware/0001DT22,
  author    = {Yu{-}Ping Wang and
               Yue{-}Jiang Dong and
               Gang Tan},
  editor    = {Paolo Bellavista and
               Kaiwen Zhang and
               Abdelouahed Gherbi and
               Saurabh Bagchi and
               Marta Pati{\~{n}}o and
               Giuseppe Di Modica and
               Julien Gascon{-}Samson},
  title     = {{ROS-SF:} {A} Transparent and Efficient {ROS} Middleware using Serialization-Free
               Message},
  booktitle = {Middleware '22: 23rd International Middleware Conference, Quebec,
               QC, Canada, November 7 - 11, 2022},
  pages     = {82--93},
  publisher = {{ACM}},
  year      = {2022},
  url       = {https://doi.org/10.1145/3528535.3531518},
  doi       = {10.1145/3528535.3531518},
  timestamp = {Wed, 01 Jun 2022 15:14:32 +0200},
  biburl    = {https://dblp.org/rec/conf/middleware/0001DT22.bib},
  bibsource = {dblp computer science bibliography, https://dblp.org}
}
```
