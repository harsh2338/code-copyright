
pragma solidity >=0.4.22 <0.9.0;
pragma experimental ABIEncoderV2;

import "./Set.sol";
contract JaccardsSimilarity {
    
    function compareStrings(string memory a, string memory b) public pure returns (bool) {
        return (keccak256(abi.encodePacked((a))) == keccak256(abi.encodePacked((b))));
    }
    function getCommonElementsCount(string[] memory list1, string[] memory list2) public view returns (uint){
        uint nl1=list1.length;
        uint nl2=list2.length;
        uint commonElementsCount=0;
        for(uint i=0;i<nl1;i++){
            for(uint j=0;j<nl2;j++){
                if(compareStrings(list1[i],list2[j])){
                    commonElementsCount++;
                    break;
                }
            }
        }
        return commonElementsCount;
    }
    function calculateSimilarityScore(string[] memory l1, string[] memory l2) public returns(uint){
        Set s1=new Set();
        for(uint i=0;i<l1.length;i++){
            s1.add(l1[i]);
        }
        Set s2=new Set();
        for(uint i=0;i<l2.length;i++){
            s2.add(l2[i]);
        }

        string[] memory list1=s1.getItems();
        string[] memory list2=s2.getItems();

        uint commonElementsCount = getCommonElementsCount(list1,list2);
        uint unionCount=list1.length+list1.length-commonElementsCount;
        uint ans= commonElementsCount/unionCount;
        return ans;
    }


}
