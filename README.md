# eecs149-249a-final-project
Emergency Responders at Railway Intersections

Goal: Have an intersection detect and control the traffic from first responders and a light-rail tram such that the first responders have priority to cross the intersection if the light-rail can stop in time.

## Environment setup
### With Conda (on laptops/your personal machine)
Create a conda environment using the .yaml file
```
conda env create -f conda_env.yaml
```
Activate with
```
conda activate train_intersect_149-249a
```

### Without (on bare metal machines)

## Directory
```
.
|-- train // Controls for the light-rail tram Pololu
|-- em_vh // Controls for the Emergency Vehicle/First Responder Pololu
|-- intersection // Logic for the intersection
|-- modules // Contains the necessary modules used by the above 3 actors
```
