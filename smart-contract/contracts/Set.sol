
pragma solidity >=0.4.22 <0.9.0;
pragma experimental ABIEncoderV2;

contract Set {
    string[] public items;

    // 1-based indexing into the array. 0 represents non-existence.
    mapping(string => uint256) indexOf;

    function add(string memory value) public {
        if (indexOf[value] == 0) {
            items.push(value);
            indexOf[value] = items.length;
        }
    }


    function contains(string memory value) public view returns (bool) {
        return indexOf[value] > 0;
    }

    function getItems() public view returns (string[] memory) {
        return items;
    }

    function count() public view returns (uint256) {
        return items.length;
    }
}
