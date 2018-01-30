# 这个文件描述怎么使用COCO给出来的python api
# demo.py文件直接放在PythonApi中的pythonapi_demo目录中

# 首先 先导入api的目录
import sys
sys.path.append("/home/triose/coco_api/cocoapi/PythonAPI/")

from pycocotools.coco import COCO
import numpy as np
import skimage.io as io
import matplotlib.pyplot as plt
import pylab
pylab.rcParams['figure.figsize'] = (8.0, 10.0)      # 显示的框的 宽度和高度

# 写绝对路径(注意: 把所有的.json文件都放在annotations目录内) 
dataDir = '/home/triose/datasets/coco/trainval'
dataType = 'val2017'
annFile = "{}/annotations/instances_{}.json".format(dataDir, dataType)


# Initialize COCO api for instance annotations
coco = COCO(annFile)

# Display COCO categories
cats = coco.loadCats(coco.getCatIds())
print()
nms = [cat['name'] for cat in cats]
print('COCO categories: \n{}\n'.format(' '.join(nms)))

# Display COCO supercategories
print("Supercategories' names:")
nms = set([cat['supercategory'] for cat in cats])
print('COCO supercategories: \n{}'.format(' '.join(nms)))

print()

# 随机选择一个图片--- 000000324158.jpg
catIds = coco.getCatIds(catNms = ['person', 'dog', 'skateboard'])
imgIds = coco.getImgIds(catIds = catIds)
imgIds = coco.getImgIds(imgIds = [324158])
img = coco.loadImgs(imgIds[np.random.randint(0, len(imgIds))])[0]

# load image
img_name = img['coco_url'].split('/')[-1]       # 这里弄了一下 img['coco_url']是个网址
local_url = dataDir + '/val2017/' + img_name    # 把名字截出来转换成本地地址
I = io.imread(local_url)

# load & display instance annotations 
plt.axis('off')
plt.imshow(I)
annIds = coco.getAnnIds(imgIds=img['id'], catIds = catIds, iscrowd = None)
anns = coco.loadAnns(annIds)
coco.showAnns(anns)
plt.show()

# initialize COCO api for person keypoints annotations
annFile = "{}/annotations/person_keypoints_{}.json".format(dataDir, dataType)
coco_kps = COCO(annFile)

# load and display keypoints annotations
plt.imshow(I)   
plt.axis('off')
ax = plt.gca()
annIds = coco_kps.getAnnIds(imgIds = img['id'], catIds = catIds, iscrowd = None)
anns = coco_kps.loadAnns(annIds)
coco_kps.showAnns(anns)
plt.show()



# 代码中所有的路径请使用绝对路径---/home/username/......



