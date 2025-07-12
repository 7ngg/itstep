import { colors, fonts } from "@/constants";
import { Image } from "expo-image";
import { LinearGradient } from "expo-linear-gradient";
import { router } from "expo-router";
import React, { useEffect } from "react";
import {
  Platform,
  StatusBar,
  StyleSheet,
  Text,
  useWindowDimensions,
} from "react-native";
import Animated, {
  useAnimatedStyle,
  useSharedValue,
  withTiming,
} from "react-native-reanimated";
import { SafeAreaView } from "react-native-safe-area-context";

const Intro = () => {
  const { width } = useWindowDimensions();
  const opacity = useSharedValue(0);

  useEffect(() => {
    const timer = setTimeout(() => {
      opacity.value = 1;
    }, 700);

    setTimeout(() => {
      router.replace("/(intro)/carousel");
    }, 1700);
    return () => clearTimeout(timer);
  }, []);
  const animatedStyles = useAnimatedStyle(() => ({
    opacity: withTiming(opacity.value * +1, {
      duration: 1000,
    }),
  }));

  return (
    <SafeAreaView
      style={{
        flex: 1,
        paddingBottom: Platform.OS === "android" ? 16 : 0,
      }}
    >
      <LinearGradient
        style={[
          StyleSheet.absoluteFill,
          {
            flex: 1,
            zIndex: 10,
          },
        ]}
        colors={["rgba(58,58,58,0)", "#3A3A3A"]}
      />
      <Image
        contentFit="cover"
        source={require("@/assets/images/bg-intro.jpg")}
        style={StyleSheet.absoluteFill}
      />
      <Animated.View
        style={[
          {
            marginTop: "auto",
            position: "relative",
            width: width - 64,
            zIndex: 11,
            marginInline: "auto",
          },
          animatedStyles,
        ]}
      >
        <Text
          style={{
            fontFamily: fonts.bold,
            fontSize: 96,
            color: colors.Primary,
          }}
        >
          Byber
        </Text>
        <Text
          style={{
            fontFamily: fonts.bold,
            fontSize: Platform.OS === "android" ? 44 : 48,
            marginTop: 8,
            color: colors.White,
          }}
        >
          Xoş gəldiniz 👋
        </Text>
        <Text
          style={{
            fontFamily: fonts.medium,
            fontSize: 18,
            marginTop: 24,
            color: colors.White,
          }}
        >
          Ən yaxşı görünüşünüz üçün peşəkar xidmətlərə bir toxunuşla sahib olun!
        </Text>
      </Animated.View>
      <StatusBar barStyle={"light-content"} />
    </SafeAreaView>
  );
};

export default Intro;
