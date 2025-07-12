import { theme } from "@/constants/theme";
import {
  Text,
  View,
  StyleSheet,
  StatusBar,
  Pressable,
  ImageBackground,
} from "react-native";
import { SafeAreaView } from "react-native-safe-area-context";
import { Colors } from "react-native/Libraries/NewAppScreen";
import { LinearGradient } from "expo-linear-gradient";
import { useState } from "react";
import Animated, {
  useSharedValue,
  withSequence,
  withSpring,
  withTiming,
} from "react-native-reanimated";
import { router } from "expo-router";
import AsyncStorage from "@react-native-async-storage/async-storage";

export default function Index() {
  const width = useSharedValue(8);
  const [index, setIndex] = useState(0);
  const handlePress = () => {
    if (index < 2) {
      setIndex((prev) => prev + 1);
    } else {
      router.push("/(dark)/(tabs)");
      AsyncStorage.setItem("hasOnBoarded", "true");
    }
  };

  const renderDots = () => (
    <>
      {[0, 1, 2].map((item, idx) => (
        <View
          key={idx}
          style={{
            backgroundColor: idx === index ? "#FFF" : "#8C8BA7",
            borderRadius: 16,
            height: 5,
            width: idx === index ? 18 : 8,
          }}
        />
      ))}
    </>
  );

  return (
    <ImageBackground
      source={require("../assets/images/bg-car.png")}
      resizeMode="cover"
      style={styles.image}
    >
      <LinearGradient
        colors={[
          "rgba(11,16,30,1)",
          "rgba(11,16,30,0.86)",
          "rgba(11,16,30,0.69)",
          "rgba(11,16,30,0)",
          "rgba(11,16,30,0)",
          "rgba(11,16,30,1)",
        ]}
        locations={[0, 0.21, 0.38, 0.55, 0.76, 1]}
        style={{
          position: "absolute",
          inset: 0,
          zIndex: 1,
        }}
      />
      <SafeAreaView style={styles.wrapper}>
        <View style={styles.container}>
          <View style={styles.pageTop}>
            <View style={styles.pageTopHeader}>
              <View
                style={{
                  paddingHorizontal: 14,
                  paddingVertical: 10,
                  borderWidth: 1,
                  borderRadius: 114,
                  borderColor: "#314FF6",
                  backgroundColor: "rgba(49, 79, 246, 0.04)",
                }}
              >
                <Text
                  style={{
                    color: "white",
                    fontSize: 14,
                    fontFamily: theme.font.medium,
                  }}
                >
                  LuxDrive
                </Text>
              </View>
              <View
                style={{
                  flexDirection: "row",
                  gap: 3,
                  alignItems: "center",
                }}
              >
                {renderDots()}
              </View>
            </View>
            <>
              {index === 0 && (
                <View style={styles.pageTopContent}>
                  <Text
                    style={{
                      color: "white",
                      fontSize: 40,
                      fontFamily: theme.font.medium,
                    }}
                  >
                    Elevate your drive with elegante.
                  </Text>
                  <Text
                    style={{
                      color: "white",
                      fontSize: 14,
                      fontFamily: theme.font.regular,
                      letterSpacing: 1.5,
                    }}
                  >
                    Discover a world of premium vehicles at your fingertips.
                    Unleash the thrill of driving in style. Your journey begins
                    here.
                  </Text>
                </View>
              )}
              {index === 1 && (
                <View style={styles.pageTopContent}>
                  <Text
                    style={{
                      color: "white",
                      fontSize: 40,
                      fontFamily: theme.font.medium,
                    }}
                  >
                    Drive your dream car!
                  </Text>
                  <Text
                    style={{
                      color: "white",
                      fontSize: 14,
                      fontFamily: theme.font.regular,
                      letterSpacing: 1.5,
                    }}
                  >
                    Discover a world of premium vehicles at your fingertips.
                    Unleash the thrill of driving in style. Your journey begins
                    here.
                  </Text>
                </View>
              )}
              {index === 2 && (
                <View style={styles.pageTopContent}>
                  <Text
                    style={{
                      color: "white",
                      fontSize: 40,
                      fontFamily: theme.font.medium,
                    }}
                  >
                    Drive into it!
                  </Text>
                  <Text
                    style={{
                      color: "white",
                      fontSize: 14,
                      fontFamily: theme.font.regular,
                      letterSpacing: 1.5,
                    }}
                  >
                    Discover a world of premium vehicles at your fingertips.
                    Unleash the thrill of driving in style. Your journey begins
                    here.
                  </Text>
                </View>
              )}
            </>
          </View>
          <Pressable
            style={{
              paddingVertical: 14,
              width: "100%",
              backgroundColor: "white",
              borderRadius: 60,
              justifyContent: "center",
              alignItems: "center",
            }}
            onPress={handlePress}
          >
            <Text
              style={{
                color: "#0A0F1D",
                fontFamily: theme.font.medium,
                fontSize: 16,
              }}
            >
              {index < 2 ? "Next" : "Les's go"}
            </Text>
          </Pressable>
        </View>
        <StatusBar />
      </SafeAreaView>
    </ImageBackground>
  );
}

const styles = StyleSheet.create({
  wrapper: {
    flex: 1,
    backgroundPosition: "0 0",
    position: "relative",
    zIndex: 3,
  },
  container: {
    flex: 1,
    paddingHorizontal: 24,
    justifyContent: "space-between",
  },
  pageTop: {
    marginTop: 8,
    gap: 45,
  },
  pageTopHeader: {
    flexDirection: "row",
    justifyContent: "space-between",
    alignItems: "center",
  },
  pageTopContent: {
    gap: 14,
  },
  image: {
    flex: 1,
    justifyContent: "center",
  },
});
