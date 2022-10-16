block, chunk and world don't get to manage anything mesh-wise,
they only hold world data

mesh stuff will get handled with mesh class maybe?
chunk mesh class contains meshes for each chunk. only to split buffers
among chunks to make lighten the burden of buffer reads by the gl
block mesh class contains meshes per block types and block visibility
world mesh class contains all the chunk meshes

world and mesh data will be synced by calls to updates to the mesh
classes

blockmesh is a blockmess right now (haha get it). please fix.

note that vec3 and others only work if constructor defined inside
struct. may have something to do with compilation