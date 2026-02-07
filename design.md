# Design Map Reduce


## Workers

Threads:
1.- Should send heartbeats to master
2.- Receive tasks from master

### Mapper
### Reducer

## Master

Master's Pseudocode:

- tasks
    - stage
- workers
    - workers

task_assignements = []


Threads:
1.- Check alive workers
2.- Assign tasks

```

bool are all mapping tasks completed()

# check dead worker thread
while true:
    
    for every living worker:
        if your last heartbeat is past x seconds:
            tag him as dead
            reschedule all his completed and ongoing mapping tasks


# heartbeat thread
while true:
    receive heartbeat
    update last heartbeat of sender


# task thread
while true:

    if there is a non completed map task
        wait for an available worker
        assign him the non completed mp task
    if there is a non completed reduce task
        wait for an available worker
        assign him a partition

```

