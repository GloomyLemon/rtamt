#ifndef STL_ABSTRACT_NODE_H
#define STL_ABSTRACT_NODE_H

#include<String>
#include<vector>
#include<memory>

/*
#include <ast/visitor/abstract_ast_visitor.hpp>
*/


namespace stl_library {



    // forward declaration
    class AbstractAstVisitor;

    class AbstractNode;
    typedef std::shared_ptr<AbstractNode> PNode;

    class AbstractNode {
        protected:
            //AbstractNode *node;
            std::string name;
            std::vector<std::string> inVars;
            std::vector<std::string> outVars;
            std::vector<PNode> children;

            void* op = nullptr;


    public:
            enum class NodeType {
                // Arithmetic / basic
                Variable,
                Constant,
                Addition,
                Subtraction,
                Multiplication,
                Division,
                Exp,
                Pow,
                Log,
                Ln,
                Sqrt,
                Negate,
                Abs,

                // LTL operators
                Always,
                Eventually,
                Disjunction,
                Conjunction,
                Until,
                Since,
                Historically,
                Once,
                Rise,
                Fall,
                Next,
                StrongNext,
                Previous,
                StrongPrevious,
                Implies,
                Iff,
                Xor,
                Not,
                Predicate,

                // STL Nodes
                TimedAlways,
                TimedEventually,
                TimedHistorically,
                TimedOnce,
                TimedPrecedes,
                TimedSince,
                TimedUntil,

                Unknown
            };

            virtual NodeType getType() const = 0;

            virtual ~AbstractNode() = default;
            AbstractNode();
            void add_child(const PNode& child);
		    void accept(AbstractAstVisitor &visitor);

    //        void getInterpreter();
    //		void setInterpreter();

		    void setName(std::string name);
            const std::string& getName() const { return name; };

		    //void setNode(AbstractNode* node);
      //      const AbstractNode* getNode() { return this->node; };

            void setChildren(const std::vector<PNode> &children);
            const std::vector<PNode>& getChildren() const { return this->children; }
		
            void setInVars(const std::vector<std::string> &vars);
            const std::vector<std::string>& getInVars() const { return this->inVars; }

            void setOutVars(const std::vector<std::string> &vars);
            const std::vector<std::string>& getOutVars() const { return this->outVars; }
		

            void setOperation(void* operation);

            void* getOperation();

       
    };

} // namespace stl_library

#endif /* STL_ABS_NODE_H */