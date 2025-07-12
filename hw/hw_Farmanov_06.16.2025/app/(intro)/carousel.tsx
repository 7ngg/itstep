import Button from "@/components/UI/Button";
import { colors, fonts } from "@/constants";
import { Image } from "expo-image";
import { router } from "expo-router";
import React, { useRef, useState } from "react";
import {
  Dimensions,
  FlatList,
  FlatListComponent,
  Platform,
  Pressable,
  StatusBar,
  StyleSheet,
  Text,
  useWindowDimensions,
  View,
} from "react-native";
import Animated, {
  useAnimatedStyle,
  useSharedValue,
  withTiming,
} from "react-native-reanimated";
import { SafeAreaView } from "react-native-safe-area-context";

const carouselPages = [
  {
    index: 0,
    text: "Bərbər və salonları əlinizin altında tapın",
    image: require("@/assets/images/carousel1.png"),
  },
  {
    index: 1,
    text: "Sevimli bərbərinizi asanlıqla bron edin",
    image: require("@/assets/images/carousel2.png"),
  },
  {
    index: 2,
    text: "Become handsome with us right now!",
    image: require("@/assets/images/carousel3.png"),
  },
];
const Carousel = () => {
  const { width } = useWindowDimensions();
  const [index, setIndex] = useState(0);
  const carouselRef = useRef<any>(null);
  const dot0Width = useSharedValue(18); // First dot starts active
  const dot1Width = useSharedValue(8);
  const dot2Width = useSharedValue(8);

  const dot0Opacity = useSharedValue(1);
  const dot1Opacity = useSharedValue(0.5);
  const dot2Opacity = useSharedValue(0.5);
  const handleNext = () => {
    if (index < 2) {
      const nextIndex = index + 1;
      setIndex(nextIndex);
      carouselRef?.current?.scrollToIndex({ index: nextIndex });
      animateDots(nextIndex);
    } else {
      router.replace("/(auth)/register");
    }
  };
  const animateDots = (activeIndex: any) => {
    const duration = 300;
    const easing = "easeInOut";

    // Reset all dots to inactive state
    dot0Width.value = withTiming(8, { duration });
    dot1Width.value = withTiming(8, { duration });
    dot2Width.value = withTiming(8, { duration });

    dot0Opacity.value = withTiming(0.5, { duration });
    dot1Opacity.value = withTiming(0.5, { duration });
    dot2Opacity.value = withTiming(0.5, { duration });

    // Animate the active dot
    switch (activeIndex) {
      case 0:
        dot0Width.value = withTiming(18, { duration });
        dot0Opacity.value = withTiming(1, { duration });
        break;
      case 1:
        dot1Width.value = withTiming(18, { duration });
        dot1Opacity.value = withTiming(1, { duration });
        break;
      case 2:
        dot2Width.value = withTiming(18, { duration });
        dot2Opacity.value = withTiming(1, { duration });
        break;
    }
  };

  // Animated styles for each dot
  const dot0Style = useAnimatedStyle(() => ({
    width: dot0Width.value,
    opacity: dot0Opacity.value,
  }));

  const dot1Style = useAnimatedStyle(() => ({
    width: dot1Width.value,
    opacity: dot1Opacity.value,
  }));

  const dot2Style = useAnimatedStyle(() => ({
    width: dot2Width.value,
    opacity: dot2Opacity.value,
  }));

  const renderDots = () => (
    <View style={styles.dotsContainer}>
      <Animated.View
        style={[
          styles.dot,
          dot0Style,
          {
            backgroundColor:
              index === 0 ? colors.Primary : colors.Greyscale["300"],
          },
        ]}
      />
      <Animated.View
        style={[
          styles.dot,
          dot1Style,
          {
            backgroundColor:
              index === 1 ? colors.Primary : colors.Greyscale["300"],
          },
        ]}
      />
      <Animated.View
        style={[
          styles.dot,
          dot2Style,
          {
            backgroundColor:
              index === 2 ? colors.Primary : colors.Greyscale["300"],
          },
        ]}
      />
    </View>
  );
  return (
    <SafeAreaView edges={["bottom"]} style={styles.wrapper}>
      <FlatList
        ref={carouselRef}
        data={carouselPages}
        horizontal
        style={{
          height: 428,
        }}
        scrollEnabled={false}
        contentContainerStyle={{
          height: 428,
        }}
        renderItem={({ item }) => (
          <Image style={styles.image} key={item.index} source={item.image} />
        )}
      />
      <View style={styles.content}>
        <Text style={styles.text}>{carouselPages[index].text}</Text>
        <View>{renderDots()}</View>
        <Button
          onPress={handleNext}
          text={index < 2 ? "Next" : "Get Started"}
        />
      </View>
      <StatusBar barStyle={"light-content"} />
    </SafeAreaView>
  );
};

export default Carousel;

const styles = StyleSheet.create({
  wrapper: {
    flex: 1,
    // paddingBottom: Platform.OS === "android" ? 16 : 0,
  },
  image: {
    height: 428,
    width: Dimensions.get("screen").width,
  },
  content: {
    flex: 1,
    marginTop: 44,
    justifyContent: "flex-end",
    alignItems: "center",
    paddingHorizontal: 24,
    paddingTop: 32,
    gap: 60,
  },
  text: {
    fontSize: 40,
    textAlign: "center",
    fontFamily: fonts.semibold,
  },
  dotsContainer: {
    flexDirection: "row",
    alignItems: "center",
    gap: 6,
  },
  dot: {
    borderRadius: 16,
    height: 5,
  },
});
