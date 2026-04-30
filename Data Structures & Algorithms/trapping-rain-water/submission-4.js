class Solution {
    /**
     * @param {number[]} height
     * @return {number}
     */
    trap(height) {
        let area = 0;

        let i = 0;
        while (i < height.length - 1) {
            if (height[i] === 0 || height[i+1] > height[i]) {
                i++;
                continue;
            }

            let j = i + 1;

            let maxima = 0;
            let maximaIdx = height.length;

            while (j < height.length) {

                if (height[j] >= height[i]) {
                    maxima = height[j];
                    maximaIdx = j;
                    break;
                }

                let smallerLeft = height[j] > height[j-1];
                let smallerRight = (j === height.length - 1) || (height[j] > height[j+1]);

                if (smallerLeft && smallerRight) {
                    if (height[j] > maxima) {
                        maxima = height[j];
                        maximaIdx = j;
                    }
                }
                
                j++;
            }

            let waterHeight = Math.min(height[i], maxima);

            let filled = 0;
            for (let k = i + 1; k < maximaIdx; k++) {
                filled += Math.min(waterHeight, height[k]);
            }

            let curArea = waterHeight * (maximaIdx - i - 1);
            curArea -= filled;
            area += Math.max(curArea, 0);
            i = maximaIdx;
        }

        return area;
    }
}
