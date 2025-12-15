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

## Directory
```
.
|-- lingua_franca // All lingua franca scripts. Built off of Lab template
  |--train // Controls for the light-rail tram Pololu
  |-- ev // Controls for the Emergency Vehicle/First Responder Pololu
|-- intersection.py // Logic for the intersection
|-- modules // Contains code testing the components needed for the intersection
```
