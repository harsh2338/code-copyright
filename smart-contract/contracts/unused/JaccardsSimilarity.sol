
pragma solidity >=0.4.22 <0.9.0;
pragma experimental ABIEncoderV2;

import "./Set.sol";
contract JaccardsSimilarity {
    
   
    function compareStrings(string memory a, string memory b) public pure returns (bool) {
        return (keccak256(abi.encodePacked((a))) == keccak256(abi.encodePacked((b))));
    }

    function getCommonElementsCount(string[] memory list1, string[] memory list2,uint setLength1,uint setLength2) public pure returns (uint){
        uint commonElementsCount=0;
        for(uint i=0;i< setLength1;i++){
            for(uint j=0;j<setLength2;j++){
                if(compareStrings(list1[i],list2[j])){
                    commonElementsCount++;
                    break;
                }
            }
        }
        return commonElementsCount;
    }

    function isPresent(string[] memory l1,string memory ele)private pure returns (bool){
        for(uint i=0;i<l1.length;i++){
          if(compareStrings(l1[i],ele)){
            return true;
          }
        }
        return false;
    }
    function calculateSimilarityScore(string[] memory l1, string[] memory l2) public pure returns(uint){

      string[] memory list1 = new string[](l1.length);   
      string[] memory list2 = new string[](l2.length);   

      uint setLength1=0;
      uint setLength2=0;

        for(uint i=0;i<l1.length;i++){
            if (!isPresent(list1,l1[i])) {
              list1[setLength1]=l1[i];
              setLength1++;
            }
        } 
  
        for(uint i=0;i<l2.length;i++){
            if (!isPresent(list2,l2[i])) {
              list2[setLength2]=l2[i];
              setLength2++;
            }
        } 

        uint commonElementsCount = getCommonElementsCount(list1,list1,setLength1,setLength2);
        uint unionCount=l1.length+l2.length-commonElementsCount;        
        
        return commonElementsCount/unionCount;
    } 


}
