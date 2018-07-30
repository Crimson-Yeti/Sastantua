# Sastantua

> Allosimanius Syneca is a cold, snowy, beautiful planet. It is so beautiful that if you stood on top of the Ice Crystal Pyramids of Sastantua, it is possible that your brain will fall out due to unobserved beauty. 

## A program that builds the Ice Crystal Pyramids of Sastantua in ascii characters for it's the user. The amount of pyramids to be built, and the sizes there of can be specified when that user calls the program.

![sastantua](https://user-images.githubusercontent.com/41135333/43361212-096aed1c-927e-11e8-815e-d5d0e6777507.PNG)

### Compiling and Running the Program

#### Compilation

sastantua.c is a complete program, and can be run through any C compiler to create an executable program that can be ran in the user's terminal.

> gcc -o sastantua sastantua.c

#### Running the Program

The executable can be given any number of pyramids to be built when called from the command line. Size must be greater than one, and the different sizes given must be delimited by a space.

> ./sastantua 1 3 5

Will output
```
Size 1
|  /*\
| /***\
|/**|**\

Size 3
|               /*\
|              /***\
|             /*****\
|          /***********\
|         /*************\
|        /***************\
|       /*****************\
|    /***********************\
|   /*************************\
|  /************|||************\
| /*************|||*************\
|/**************|||**************\

Size 5
|                                  /*\
|                                 /***\
|                                /*****\
|                             /***********\
|                            /*************\
|                           /***************\
|                          /*****************\
|                       /***********************\
|                      /*************************\
|                     /***************************\
|                    /*****************************\
|                   /*******************************\
|               /***************************************\
|              /*****************************************\
|             /*******************************************\
|            /*********************************************\
|           /***********************************************\
|          /*************************************************\
|      /*********************************************************\
|     /***********************************************************\
|    /****************************|||||****************************\
|   /*****************************|||||*****************************\
|  /******************************|||$|******************************\
| /*******************************|||||*******************************\
|/********************************|||||********************************\
```

If an invalid size is given an error will be printed in place of a pyramid

> ./sastantua 1 a 2

Will output
```
Size 1
|  /*\
| /***\
|/**|**\


***Argument "a" Invalid***


Size 2
|        /*\
|       /***\
|      /*****\
|   /***********\
|  /*************\
| /***************\
|/********|********\
```

### Size Input

  
