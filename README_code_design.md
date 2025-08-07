<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-generate-toc again -->
**Table of Contents**

- [Packages](#packages)

<!-- markdown-toc end -->

# Packages

The python code base is divided in the following separate packages:

- syntax: definition of the STL data structure, consisting of node defitions and a node visitor to model the structure of STL formulas.
- semantics: definitions of various time semantics (discrete, dense) and offline/online solvers. It contains the implementations of STL operators and visitors to update new signal values.
- spec: definition of the 'front end' on how to call and select the desired semantics.
- pastify: a package that is used to transform STL formulas with future-operators to transform them to equivalant past-operators.

Due to the presence of multiple semantics on how to interpret the formalism (dense time vs discrete time, and offline vs online), the syntax is separated from the semantics. 
TODO check this This means there is a general purpose AST to store the STL formula, used by multiple implementations of semantics. A spec package is then used to neatly combine AST and the desired semantics through an interpreter instantiation.

# Syntax

The syntax package consists of two parts: the node structure to store abstract syntax trees and the AST handler structure to build an AST (parser) and to traverse them (visitor). 

- node:
  - abstract node: getter/setters for node properties such as name (names are subformula) and references to children node.
    - binary node: for binary operators, such as addition, multiplication
	- unary node: for unary operators, such as not, finally
	- leaf node: for leaf nodes, constants and variables/signals
- ast:
  - parser: transforms tokens to nodes to build an abstract syntax tree, only implemented in python, not in C++
  - visitor: abstract classes that traverse the abstract syntax tree in a depth first search manner, visiting all the nodes in the formulas

# Semantics

The semantics package contains the computation aspects. Various semantics are defined in abstract classes that handle concepts for those semantics. 
For example, the discrete semantics has functions to transform intervals and sample frequency to equivalent circular buffer sizes.

- online discrete semantics:
  - Defines an 'operation' for each node in the ast to handle updated samples
  - Maintains an operation dictionary to store and access the operations used in an AST
    - The operation dictionary is created ahead of the first sample being fed to the STL solver through a specialized visitor.
	- Temporal operations are assigned a circular buffer that maintains all samples relevant for evaluating the operator.
	  - The circular buffer size is equal to the interval size (i.e. end - start) divided by the sample frequency. 
  - Maintains a variable/signal value dictionary. Each update cycle, the new signal values are set in this dictionary.
  - Each update cycle, a visitor traverses the AST. 
    - For each visited node, it retrieves the operator from the operator dictionary. 
	- If it is a leaf, it will return the value of the constant or variable. 
	- Otherwise, it will use the returned values for the child(ren) and return the new value.
  
  - Online sample input is a dictionary of variable/signal name to its value. Only provided variables/signals are updated in the variable dictionary.
  
  - Sampling
	- Timing
	- Signal values
	  - TODO Should all signals by present? Explain how this is checked and enforced
	

  
- offline discrete semantics:
  - TODO
  
- online dense time semantics:
  - TODO

- offline dense time semantics:
  - TODO
  
# Spec

The specification package contains helper classes to specifify the AST and the desired semantics. It contains functionality like pastify to transform future-formulas to equivalent past-formulas. 
It also has the update method to provide new samples for online semantics.

# Pastify

TODO