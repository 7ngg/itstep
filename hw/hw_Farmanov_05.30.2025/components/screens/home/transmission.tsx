import { theme } from "@/constants/theme";
import { useState } from "react";
import {
  TouchableOpacity,
  Text,
  View,
  FlatList,
  StyleSheet,
} from "react-native";
import { Image } from "expo-image";
import { useNavigation } from "@react-navigation/native";
import { router } from "expo-router";

const transmission = {
  automatic: {
    id: 1,
    name: "Automatic",
  },
  manual: {
    id: 2,
    name: "Manual",
  },
  electric: {
    id: 3,
    name: "Electric",
  },
  cvt: {
    id: 4,
    name: "CVT",
  },
};

const TransmissionScreen = () => {
  const [selectedTransmission, setSelectedTransmission] = useState<
    number | null
  >(1);
  const navigation = useNavigation();
  const renderItem = ({
    item,
  }: {
    item: (typeof transmission)[keyof typeof transmission];
  }) => {
    const isActive = item.id === selectedTransmission;
    return (
      <TouchableOpacity
        onPress={() => setSelectedTransmission(item.id)}
        style={[
          styles.transmissionItem,
          {
            backgroundColor: isActive ? "#314FF6" : "rgba(255, 255, 255, 0.04)",
          },
        ]}
      >
        <Text style={styles.transmissionText}>{item.name}</Text>
      </TouchableOpacity>
    );
  };

  return (
    <View style={styles.container}>
      <View style={styles.section}>
        <Text style={styles.sectionTitle}>Select by transmission</Text>
        <View style={styles.flatListContainer}>
          <FlatList
            horizontal
            data={Object.values(transmission)}
            renderItem={renderItem}
            keyExtractor={(item) => item.id.toString()}
            contentContainerStyle={styles.flatListContent}
            showsHorizontalScrollIndicator={false}
          />
        </View>
      </View>

      <View style={styles.carCard}>
        <View style={styles.carHeader}>
          <Text style={styles.carTitle}>Mercedes SL 63</Text>
          <Text style={styles.carPrice}>
            2500 AED/<Text style={styles.priceSubtext}>day</Text>
          </Text>
        </View>

        <View style={styles.carSpecs}>
          <View style={styles.specItem}>
            <Image
              source={require("@/assets/images/speedometer.png")}
              style={styles.specIcon}
            />
            <Text style={styles.specText}>585 hp</Text>
          </View>

          <View style={styles.specDivider} />

          <View style={styles.specItem}>
            <Image
              source={require("@/assets/images/transmission.png")}
              style={styles.specIcon}
            />
            <Text style={styles.specText}>Automatic</Text>
          </View>

          <View style={styles.specDivider} />

          <View style={styles.specItem}>
            <Image
              source={require("@/assets/images/Car-seats.png")}
              style={styles.specIcon}
            />
            <Text style={styles.specText}>4 Seats</Text>
          </View>
        </View>

        <View style={styles.carImageContainer}>
          <Image
            source={require("@/assets/images/mercedes.png")}
            style={styles.carImage}
          />
        </View>
        <View style={{alignItems: "center", }}>
          <TouchableOpacity
            style={styles.infoButton}
            onPress={() => router.push("/(dark)/detail")}
          >
            <Text style={styles.infoButtonText}>Info</Text>
          </TouchableOpacity>
        </View>
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    marginBottom: 20,
  },
  section: {
    marginBottom: 30,
  },
  sectionTitle: {
    fontFamily: theme.font.medium,
    fontSize: 20,
    color: "#fff",
    marginBottom: 16,
  },
  flatListContainer: {
    height: 50,
  },
  flatListContent: {
    gap: 10,
  },
  transmissionItem: {
    width: 100,
    height: 45,
    borderRadius: 30,
    alignItems: "center",
    justifyContent: "center",
  },
  transmissionText: {
    fontFamily: theme.font.regular,
    fontSize: 16,
    color: "#fff",
  },
  infoButton: {
    backgroundColor: "#314FF6",
    width: 150,
    paddingVertical: 4,
    borderRadius: 20,
    alignItems: "center",
  },
  infoButtonText: {
    color: "#fff",
    fontFamily: theme.font.medium,
    fontSize: 14,
  },
  carCard: {
    borderRadius: 10,
    backgroundColor: "rgba(255, 255, 255, 0.04)",
    paddingHorizontal: 25,
    paddingVertical: 20,
  },
  carHeader: {
    flexDirection: "row",
    alignItems: "center",
    justifyContent: "space-between",
    marginBottom: 8,
  },
  carTitle: {
    fontFamily: theme.font.medium,
    fontSize: 20,
    color: "#fff",
  },
  carPrice: {
    fontFamily: theme.font.medium,
    fontSize: 14,
    color: "#fff",
    backgroundColor: "rgba(255, 255, 255, 0.04)",
    borderColor: "rgba(255, 255, 255, 0.07)",
    paddingHorizontal: 14,
    paddingVertical: 12,
    borderRadius: 20,
    borderWidth: 1,
  },
  priceSubtext: {
    color: "#8C8BA7",
  },
  carSpecs: {
    flexDirection: "row",
    alignItems: "center",
    gap: 15,
    marginTop: 8,
  },
  specItem: {
    flexDirection: "row",
    alignItems: "center",
    gap: 3,
  },
  specIcon: {
    width: 14,
    height: 14,
  },
  specText: {
    fontFamily: theme.font.regular,
    fontSize: 12,
    color: "#fff",
  },
  specDivider: {
    width: 1,
    height: 20,
    borderColor: "rgba(255, 255, 255, 0.07)",
    borderWidth: 1,
  },
  carImageContainer: {
    marginTop: 16,
    alignItems: "center",
  },
  carImage: {
    width: 277,
    height: 150,
    borderRadius: 10,
    resizeMode: "contain",
  },
});

export default TransmissionScreen;
