var Index = new Vue({
	el: '#app',
	data: {
		bannerList: [
			{path: "images/banner01.jpeg", name: "banner01", id: 1},
			{path: "images/banner02.jpeg", name: "banner02", id: 2},
			{path: "images/banner03.jpeg", name: "banner03", id: 3},
			{path: "images/banner04.jpeg", name: "banner04", id: 4},
			{path: "images/banner05.jpeg", name: "banner05", id: 5},
			{path: "images/banner06.jpeg", name: "banner06", id: 6},
			{path: "images/banner07.jpeg", name: "banner07", id: 7},
			{path: "images/banner08.jpeg", name: "banner08", id: 8}
		],
		hotVideo: [
			{path: "images/banner01.jpeg", name: "斗罗大陆番外篇第一百零三集啦啦啦啦啦啦啦", subName: "斗罗大陆番外篇第一百零三集主要讲的是零零落落零零落落零零落落了", id: 1},
			{path: "images/banner02.jpeg", name: "斗罗大陆番外篇第一百零三集啦啦啦啦啦啦啦", subName: "斗罗大陆番外篇第一百零三集主要讲的是零零落落零零落落零零落落了", id: 2},
			{path: "images/banner03.jpeg", name: "斗罗大陆番外篇第一百零三集啦啦啦啦啦啦啦", subName: "斗罗大陆番外篇第一百零三集主要讲的是零零落落零零落落零零落落了", id: 3},
			{path: "images/banner04.jpeg", name: "斗罗大陆番外篇第一百零三集啦啦啦啦啦啦啦", subName: "斗罗大陆番外篇第一百零三集主要讲的是零零落落零零落落零零落落了", id: 4},
			{path: "images/banner05.jpeg", name: "斗罗大陆番外篇第一百零三集啦啦啦啦啦啦啦", subName: "斗罗大陆番外篇第一百零三集主要讲的是零零落落零零落落零零落落了", id: 5},
			{path: "images/banner06.jpeg", name: "斗罗大陆番外篇第一百零三集啦啦啦啦啦啦啦", subName: "斗罗大陆番外篇第一百零三集主要讲的是零零落落零零落落零零落落了", id: 6},
			{path: "images/banner07.jpeg", name: "斗罗大陆番外篇第一百零三集啦啦啦啦啦啦啦", subName: "斗罗大陆番外篇第一百零三集主要讲的是零零落落零零落落零零落落了", id: 7}
		],
		hotVideo2: [
			{path: "images/banner01.jpeg", name: "斗罗大陆番外篇第一百零三集啦啦啦啦啦啦啦", subName: "斗罗大陆番外篇第一百零三集主要讲的是零零落落零零落落零零落落了", id: 1},
			{path: "images/banner02.jpeg", name: "斗罗大陆番外篇第一百零三集啦啦啦啦啦啦啦", subName: "斗罗大陆番外篇第一百零三集主要讲的是零零落落零零落落零零落落了", id: 2},
			{path: "images/banner03.jpeg", name: "斗罗大陆番外篇第一百零三集啦啦啦啦啦啦啦", subName: "斗罗大陆番外篇第一百零三集主要讲的是零零落落零零落落零零落落了", id: 3},
			{path: "images/banner04.jpeg", name: "斗罗大陆番外篇第一百零三集啦啦啦啦啦啦啦", subName: "斗罗大陆番外篇第一百零三集主要讲的是零零落落零零落落零零落落了", id: 4},
			{path: "images/banner05.jpeg", name: "斗罗大陆番外篇第一百零三集啦啦啦啦啦啦啦", subName: "斗罗大陆番外篇第一百零三集主要讲的是零零落落零零落落零零落落了", id: 5},
			{path: "images/banner06.jpeg", name: "斗罗大陆番外篇第一百零三集啦啦啦啦啦啦啦", subName: "斗罗大陆番外篇第一百零三集主要讲的是零零落落零零落落零零落落了", id: 6},
			{path: "images/banner07.jpeg", name: "斗罗大陆番外篇第一百零三集啦啦啦啦啦啦啦", subName: "斗罗大陆番外篇第一百零三集主要讲的是零零落落零零落落零零落落了", id: 7}
		],
		bannerRef: null,
		activeBanner: 0
	},
	created() { },
	mounted() {
		this.initBanner()
	},
	methods: {
		initBanner() {
			this.bannerRef = new Swiper('.swiper-container', {
				speed: 1000,
				longSwipes: false,
				loop: true,
				autoplay: {
					disableOnInteraction: false,
				},
				pagination: {
					el: '.swiper-pagination',
					// type: 'custom', // 自定义-分页器
					clickable: true,
					renderBullet: (index, className) => {
						let text = '';
						this.bannerList.forEach((item, i) => {
							if (index == i) text = item.name
						});
						return '<div class="' + className + '"><span class="name">' + text + '</span></div>';
					}
				},
				on: {

				}
			});
		},
		// 自定义-分页器
		paginationClick(index) {
			this.activeBanner = index
			this.bannerRef.slideTo(index, 1000, false);
		}
	},
	filters: {}
});
